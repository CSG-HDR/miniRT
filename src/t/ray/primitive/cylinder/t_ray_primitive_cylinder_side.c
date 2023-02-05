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

#include "t_ray_primitive_cylinder.h"

#include "ft_types.h"
#include "t_f.h"
#include "t_f3.h"
#include "t_map.h"
#include "t_ray.h"

static t_vars	s_vars(t_ray ray, t_map_cylinder cylinder)
{
	t_vars	l;

	l.self = cylinder;
	l.a = 1 / (cylinder.size.x * cylinder.size.x);
	l.b = 1 / (cylinder.size.y * cylinder.size.y);
	l.p = ray.origin.x;
	l.q = ray.origin.y;
	l.u = ray.direction.x;
	l.v = ray.direction.y;
	l.x = (l.a * l.u * l.u) + (l.b * l.v * l.v);
	l.y = (2 * l.a * l.p * l.u) + (2 * l.b * l.q * l.v);
	l.z = (l.a * l.p * l.p) + (l.b * l.q * l.q) - 1;
	l.y2_4xz = l.y * l.y - 4 * l.x * l.z;
	l.hit = l.y2_4xz > 0;
	if (l.hit)
		l.sqrt_y2_4xz = t_f_sqrt(l.y2_4xz);
	l.has_record = (l.hit && (l.y < l.sqrt_y2_4xz));
	return (l);
}

typedef struct s_locals
{
	t_f				n_distance;
	t_map_position	n;
	bool			n_hit;
	t_f3			n_normal;
	t_f				n_x;
	t_f				n_y;
	t_f				f_distance;
	t_map_position	f;
	bool			f_hit;
	t_f3			f_normal;
	t_f				f_x;
	t_f				f_y;
}	t_locals;

static t_locals	s_locals(t_vars a, t_ray ray)
{
	t_locals	l;

	l.n_distance = (-a.y - a.sqrt_y2_4xz) / (2 * a.x);
	l.n = t_f3_add(ray.origin, t_f3_mul(ray.direction, l.n_distance));
	l.n_hit = (l.n_distance >= 0 && l.n.z >= 0 && l.n.z <= a.self.size.z);
	if (l.n_hit)
	{
		l.n_normal = t_ray_primitive_cylinder_side_normal(a, l.n);
		l.n_x = t_f_rot(t_f_atan2(l.n.y, l.n.x));
		l.n_y = l.n.z / a.self.size.z;
	}
	l.f_distance = (-a.y + a.sqrt_y2_4xz) / (2 * a.x);
	l.f = t_f3_add(ray.origin, t_f3_mul(ray.direction, l.f_distance));
	l.f_hit = (l.f_distance >= 0 && l.f.z >= 0 && l.f.z <= a.self.size.z);
	if (l.f_hit)
	{
		l.f_normal = t_ray_primitive_cylinder_side_normal(a, l.f);
		l.f_x = t_f_rot(t_f_atan2(l.f.y, l.f.x));
		l.f_y = l.f.z / a.self.size.z;
	}
	return (l);
}

t_err	t_ray_primitive_cylinder_side(
	t_ray ray,
	t_map_cylinder cylinder,
	t_ray_hit_records_builder *builder
)
{
	const t_vars	a = s_vars(ray, cylinder);
	t_locals		l;

	if (!a.has_record)
		return (false);
	l = s_locals(a, ray);
	return (
		false
		|| (l.n_hit
			&& t_ray_hit_records_builder_add(builder, (t_ray_hit_record){
				l.n_distance, l.n_normal,
				t_ray_material_from_color(cylinder.material_side),
				true, l.n_x, l.n_y}))
		|| (l.f_hit
			&& t_ray_hit_records_builder_add(builder, (t_ray_hit_record){
				l.f_distance, l.f_normal,
				t_ray_material_from_color(cylinder.material_side),
				false, l.f_x, l.f_y}))
	);
}
