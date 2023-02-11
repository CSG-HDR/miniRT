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

#include "t_ray.h"

#include <stdbool.h>

#include "ft_types.h"
#include "t_f.h"
#include "t_map.h"

typedef struct s_quadric_vars
{
	t_f	a;
	t_f	b;
	t_f	c;
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

	v.a = r.origin.x;
	v.b = r.origin.y;
	v.c = r.origin.z;
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
	equation.b = 2 * q.a * v.a * v.u + 2 * q.b * v.b * v.v + 2 * q.c * v.c * v.w
		+ q.d * v.a * v.v + q.d * v.b * v.u + q.e * v.b * v.w + q.e * v.c * v.v
		+ q.f * v.a * v.w + q.f * v.c * v.u + q.g * v.u + q.h * v.v + q.i * v.w;
	equation.c = q.a * v.a * v.a + q.b * v.b * v.b + q.c * v.c * v.c
		+ q.d * v.a * v.b + q.e * v.b * v.c + q.f * v.a * v.c
		+ q.g * v.a + q.h * v.b + q.i * v.c + q.j;
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
	*out_distance = (-eq.b - t_f_sqrt(discriminant)) / 2 * eq.a;
	if (*out_distance < 0)
		*out_is_front_face = true;
	else
	{
		*out_distance = (-eq.b + t_f_sqrt(discriminant)) / 2 * eq.a;
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
