/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ray_nearest_quadric.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2023/02/25 14:49:15 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_ray.h"

#include <stdbool.h>

#include "ft_types.h"
#include "t_f.h"
#include "t_map.h"

typedef struct s_quadric_vars
{
	t_f	p;
	t_f	q;
	t_f	r;
	t_f	u;
	t_f	v;
	t_f	w;
}	t_quadric_vars;

typedef struct s_quadric_equation
{
	t_f	a;
	t_f	b;
	t_f	c;
}	t_quadric_equation;

static t_quadric_vars	s_quadric_vars(t_ray r)
{
	t_quadric_vars	v;

	v.p = r.origin.x;
	v.q = r.origin.y;
	v.r = r.origin.z;
	v.u = r.direction.x;
	v.v = r.direction.y;
	v.w = r.direction.z;
	return (v);
}

static t_quadric_equation	s_equation(t_map_quadric q, t_ray r)
{
	const t_quadric_vars	v = s_quadric_vars(r);
	t_quadric_equation		equation;

	equation.a = q.a * v.u * v.u + q.b * v.v * v.v + q.c * v.w * v.w
		+ q.d * v.u * v.v + q.e * v.v * v.w + q.f * v.u * v.w;
	equation.b = 2 * q.a * v.p * v.u + 2 * q.b * v.q * v.v + 2 * q.c * v.r * v.w
		+ q.d * v.p * v.v + q.d * v.q * v.u + q.e * v.q * v.w + q.e * v.r * v.v
		+ q.f * v.p * v.w + q.f * v.r * v.u + q.g * v.u + q.h * v.v + q.i * v.w;
	equation.c = q.a * v.p * v.p + q.b * v.q * v.q + q.c * v.r * v.r
		+ q.d * v.p * v.q + q.e * v.q * v.r + q.f * v.p * v.r
		+ q.g * v.p + q.h * v.q + q.i * v.r + q.j;
	return (equation);
}

static bool	s_distance(
	t_map_quadric q,
	t_ray r,
	t_f *out_distance,
	bool *out_is_front_face
)
{
	const t_quadric_equation	eq = s_equation(q, r);
	const t_f					discriminant = eq.b * eq.b - 4 * eq.a * eq.c;

	if (discriminant < 0)
		return (false);
	*out_distance = (-eq.b - t_f_sqrt(discriminant)) / (2 * eq.a);
	if (*out_distance > 0)
		*out_is_front_face = true;
	else
	{
		*out_distance = (-eq.b + t_f_sqrt(discriminant)) / (2 * eq.a);
		if (*out_distance < 0)
			return (false);
		*out_is_front_face = false;
	}
	return (true);
}

static t_map_normal	s_normal(t_map_quadric q, t_map_position p)
{
	return (t_f3_unit((t_map_normal){
			2 * q.a * p.x + q.d * p.y + q.f * p.z + q.g,
			2 * q.b * p.y + q.d * p.x + q.e * p.z + q.h,
			2 * q.c * p.z + q.e * p.y + q.f * p.x + q.i
		}));
}

t_err	t_ray_nearest_quadric(
	t_ray ray,
	t_map_quadric quadric,
	t_ray_hit_records *out
)
{
	t_ray_hit_records_builder	*builder;
	t_f							distance;
	bool						is_front_face;
	t_map_position				point;
	t_map_normal				normal;

	if (s_distance(quadric, ray, &distance, &is_front_face))
	{
		if (t_ray_hit_records_builder_init(&builder))
			return (true);
		point = t_f3_add(ray.origin, t_f3_mul(ray.direction, distance));
		normal = s_normal(quadric, point);
		if ((t_ray_hit_records_builder_add(builder, (t_ray_hit_record){distance,
					normal, t_ray_material_from_computed(quadric.material),
					is_front_face, 0, 0})
		) || t_ray_hit_records_builder_build(builder, out))
		{
			t_ray_hit_records_builder_free(builder);
			return (true);
		}
		t_ray_hit_records_builder_free(builder);
	}
	else
		*out = (t_ray_hit_records){0, NULL};
	return (false);
}
