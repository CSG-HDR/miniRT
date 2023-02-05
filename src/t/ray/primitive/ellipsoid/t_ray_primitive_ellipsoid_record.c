/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_file_name (file name is useless too)          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42header-remover <whatever@example.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by file history     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_ray_primitive_ellipsoid.h"

#include "wrap.h"
#include "ft_types.h"
#include "t_f.h"
#include "t_f3.h"
#include "t_map.h"
#include "t_ray.h"

static t_vars	s_vars(t_ray ray, t_map_ellipsoid ellipsoid)
{
	t_vars	l;

	l.a = 1 / (ellipsoid.size.x * ellipsoid.size.x);
	l.b = 1 / (ellipsoid.size.y * ellipsoid.size.y);
	l.c = 1 / (ellipsoid.size.z * ellipsoid.size.z);
	l.p = ray.origin.x;
	l.q = ray.origin.y;
	l.r = ray.origin.z;
	l.u = ray.direction.x;
	l.v = ray.direction.y;
	l.w = ray.direction.z;
	l.x = (l.a * l.u * l.u) + (l.b * l.v * l.v) + (l.c * l.w * l.w);
	l.y = (2 * l.a * l.p * l.u) + (2 * l.b * l.q * l.v) + (2 * l.c * l.r * l.w);
	l.z = (l.a * l.p * l.p) + (l.b * l.q * l.q) + (l.c * l.r * l.r) - 1;
	l.y2_4xz = l.y * l.y - 4 * l.x * l.z;
	l.hit = l.y2_4xz > 0;
	if (l.hit)
		l.sqrt_y2_4xz = t_f_sqrt(l.y2_4xz);
	l.has_record = (l.hit && (l.y < l.sqrt_y2_4xz));
	l.in_ellipsoid = (l.has_record && (-l.y - l.sqrt_y2_4xz < 0));
	l.self = ellipsoid;
	return (l);
}

static t_err	front(t_vars l, t_ray ray, t_ray_hit_records_builder *builder)
{
	const t_f				distance = (-l.y - l.sqrt_y2_4xz) / (2 * l.x);
	const t_map_position	point
		= t_f3_add(ray.origin, t_f3_mul(ray.direction, distance));
	t_map_normal			normal;
	t_f						coord_x;
	t_f						coord_y;

	if (distance <= 0)
		return (t_ray_hit_records_builder_add(
				builder, t_ray_default_hit_record(l.self.material)));
	normal = t_ray_primitive_ellipsoid_normal(l, point);
	t_ray_primitive_ellipsoid_coord(point, l.self.size, &coord_x, &coord_y);
	return (
		t_ray_hit_records_builder_add(builder, (t_ray_hit_record){
			distance,
			normal,
			t_ray_material_from_color(l.self.material),
			true,
			coord_x,
			coord_y,
		})
	);
}

static t_err	back(t_vars l, t_ray ray, t_ray_hit_records_builder *builder)
{
	const t_f				distance = (-l.y + l.sqrt_y2_4xz) / (2 * l.x);
	const t_map_position	point
		= t_f3_add(ray.origin, t_f3_mul(ray.direction, distance));
	t_map_normal			normal;
	t_f						coord_x;
	t_f						coord_y;

	normal = t_ray_primitive_ellipsoid_normal(l, point);
	t_ray_primitive_ellipsoid_coord(point, l.self.size, &coord_x, &coord_y);
	return (
		t_ray_hit_records_builder_add(builder, (t_ray_hit_record){
			distance,
			normal,
			t_ray_material_from_color(l.self.material),
			false,
			coord_x,
			coord_y,
		})
	);
}

t_err	t_ray_primitive_ellipsoid_record(
	t_ray ray,
	t_map_ellipsoid ellipsoid,
	t_ray_hit_records_builder *builder
)
{
	const t_vars	l = s_vars(ray, ellipsoid);

	if (!l.hit)
		return (false);
	return (
		false
		|| front(l, ray, builder)
		|| back(l, ray, builder)
	);
}
