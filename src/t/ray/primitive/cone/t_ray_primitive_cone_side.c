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

#include "t_ray_primitive_cone.h"

#include "ft_types.h"
#include "t_f.h"
#include "t_f3.h"
#include "t_map.h"
#include "t_ray.h"

/**
 * f(x, y, z) = x^2/a^2 + y^2/b^2 - z^2/c^2 = 0
 * f(ray.position + ray.direction * distance) = 0
 * f(p+ut, q+vt, r+wt) = 0
 *
 * A = 1/a^2, B = 1/b^2, C = 1/c^2
 * Ax^2 + By^2 - Cz^2 = 0
 * Ap^2 + 2Aput + Au^2t^2 + Bq^2 + 2Bqvt + Bv^2t^2 - Cr^2 - 2Crwt - Cw^2t^2 = 0
 * X = Au^2 + Bv^2 - Cw^2
 * Y = 2Apu + 2Bqv - 2Crw
 * Z = Ap^2 + Bq^2 - Cr^2
 * t = (-Y +- sqrt(Y^2 - 4XZ)) / 2X
 */
typedef struct s_locals1
{
	t_f			a;
	t_f			b;
	t_f			c;
	t_f			p;
	t_f			q;
	t_f			r;
	t_f			u;
	t_f			v;
	t_f			w;
	t_f			x;
	t_f			y;
	t_f			z;
	t_f			y2_4xz;
	bool		hit;
	bool		has_record;
	t_f			sqrt_y2_4xz;
	t_map_cone	self;
}	t_locals1;

static t_locals1	s_locals1(t_ray ray, t_map_cone cone)
{
	t_locals1	l;

	l.self = cone;
	l.a = 1 / (cone.size.x * cone.size.x);
	l.b = 1 / (cone.size.y * cone.size.y);
	l.c = 1 / (cone.size.z * cone.size.z);
	l.p = ray.origin.x;
	l.q = ray.origin.y;
	l.r = ray.origin.z;
	l.u = ray.direction.x;
	l.v = ray.direction.y;
	l.w = ray.direction.z;
	l.x = (l.a * l.u * l.u) + (l.b * l.v * l.v) - (l.c * l.w * l.w);
	l.y = (2 * l.a * l.p * l.u) + (2 * l.b * l.q * l.v) - (2 * l.c * l.r * l.w);
	l.z = (l.a * l.p * l.p) + (l.b * l.q * l.q) - (l.c * l.r * l.r);
	l.y2_4xz = l.y * l.y - 4 * l.x * l.z;
	l.hit = l.y2_4xz > 0;
	if (l.hit)
		l.sqrt_y2_4xz = t_f_sqrt(l.y2_4xz);
	l.has_record = (l.hit && (l.y < l.sqrt_y2_4xz));
	return (l);
}

// TODO: normal
static t_map_normal	normal(t_map_position point, t_locals1 l)
{
	(void)point;
	(void)l;
	return ((t_map_normal){0, 0, 0});
}

typedef struct s_locals2
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
}	t_locals2;

static t_locals2	s_locals2(t_locals1 a, t_ray ray)
{
	t_locals2	l;

	l.n_distance = (-a.y - a.sqrt_y2_4xz) / (2 * a.x);
	l.n = t_f3_add(ray.origin, t_f3_mul(ray.direction, l.n_distance));
	l.n_hit = (l.n.z >= 0 && l.n.z <= a.self.size.z);
	if (l.n_hit)
	{
		l.n_normal = normal(l.n, a);
		l.n_x = t_f_rot(t_f_atan2(l.n.y, l.n.x));
		l.n_y = l.n.z / a.self.size.z;
	}
	l.f_distance = (-a.y + a.sqrt_y2_4xz) / (2 * a.x);
	l.f = t_f3_add(ray.origin, t_f3_mul(ray.direction, l.f_distance));
	l.f_hit = (l.f.z >= 0 && l.f.z <= a.self.size.z);
	if (l.f_hit)
	{
		l.f_normal = normal(l.f, a);
		l.f_x = t_f_rot(t_f_atan2(l.f.y, l.f.x));
		l.f_y = l.f.z / a.self.size.z;
	}
	return (l);
}

t_err	t_ray_primitive_cone_side(
	t_ray ray,
	t_map_cone cone,
	t_ray_hit_records_builder *builder
)
{
	const t_ray		enhanced = {(t_map_position){
		ray.origin.x, ray.origin.y, ray.origin.z - cone.size.z}, ray.direction};
	const t_locals1	a = s_locals1(enhanced, cone);
	t_locals2		l;

	if (!a.has_record)
		return (false);
	l = s_locals2(a, ray);
	return (
		false
		|| (l.n_hit
			&& t_ray_hit_records_builder_add(builder, (t_ray_hit_record){
				l.n_distance, l.n_normal,
				t_ray_material_from_color(cone.material_side),
				true, l.n_x, l.n_y}))
		|| (l.f_hit
			&& t_ray_hit_records_builder_add(builder, (t_ray_hit_record){
				l.f_distance, l.f_normal,
				t_ray_material_from_color(cone.material_side),
				false, l.f_x, l.f_y}))
	);
}
