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

typedef void		(*t_func)(
	t_ray_nearest_quartic_vars v,
	t_map_quartic q,
	t_ray_nearest_quartic_equation *mut_result);

static const t_func	g_funcs[35] = {
	t_ray_nearest_quartic_c400,
	t_ray_nearest_quartic_c040,
	t_ray_nearest_quartic_c004,
	t_ray_nearest_quartic_c310,
	t_ray_nearest_quartic_c301,
	t_ray_nearest_quartic_c130,
	t_ray_nearest_quartic_c031,
	t_ray_nearest_quartic_c103,
	t_ray_nearest_quartic_c013,
	t_ray_nearest_quartic_c220,
	t_ray_nearest_quartic_c022,
	t_ray_nearest_quartic_c202,
	t_ray_nearest_quartic_c211,
	t_ray_nearest_quartic_c121,
	t_ray_nearest_quartic_c112,
	t_ray_nearest_quartic_c300,
	t_ray_nearest_quartic_c030,
	t_ray_nearest_quartic_c003,
	t_ray_nearest_quartic_c210,
	t_ray_nearest_quartic_c201,
	t_ray_nearest_quartic_c120,
	t_ray_nearest_quartic_c021,
	t_ray_nearest_quartic_c102,
	t_ray_nearest_quartic_c012,
	t_ray_nearest_quartic_c111,
	t_ray_nearest_quartic_c200,
	t_ray_nearest_quartic_c020,
	t_ray_nearest_quartic_c002,
	t_ray_nearest_quartic_c110,
	t_ray_nearest_quartic_c011,
	t_ray_nearest_quartic_c101,
	t_ray_nearest_quartic_c100,
	t_ray_nearest_quartic_c010,
	t_ray_nearest_quartic_c001,
	t_ray_nearest_quartic_c000,
};

static t_ray_nearest_quartic_vars	quartic_vars(t_ray r)
{
	t_ray_nearest_quartic_vars	v;

	v.p = r.origin.x;
	v.q = r.origin.y;
	v.r = r.origin.z;
	v.u = r.direction.x;
	v.v = r.direction.y;
	v.w = r.direction.z;
	return (v);
}

static t_ray_nearest_quartic_equation	equation(t_map_quartic q, t_ray r)
{
	const t_ray_nearest_quartic_vars	v = quartic_vars(r);
	t_ray_nearest_quartic_equation		equation;
	size_t								i;

	equation.a = (t_f)0;
	equation.b = (t_f)0;
	equation.c = (t_f)0;
	equation.d = (t_f)0;
	equation.e = (t_f)0;
	i = -1;
	while (++i < 35)
		g_funcs[i](v, q, &equation);
	return (equation);
}

static bool	s_distance(
	t_map_quartic q,
	t_ray r,
	t_f *out_distance,
	bool *out_is_front_face
)
{
	const t_ray_nearest_quartic_equation	eq = equation(q, r);

	(void)out_distance;
	(void)out_is_front_face;
	(void)eq;
	(void)g_funcs;
	return (false);
}

static t_map_normal	s_normal(t_map_quartic q, t_map_position p)
{
	(void)p;
	(void)q;
	return (t_f3_unit((t_map_normal){(t_f)0, (t_f)0, (t_f)0}));
}

t_err	t_ray_nearest_quartic(
	t_ray ray,
	t_map_quartic quartic,
	t_ray_hit_records *out
)
{
	t_ray_hit_records_builder	*builder;
	t_f							distance;
	bool						is_front_face;
	t_map_position				point;
	t_map_normal				normal;

	if (s_distance(quartic, ray, &distance, &is_front_face))
	{
		if (t_ray_hit_records_builder_init(&builder))
			return (true);
		point = t_f3_add(ray.origin, t_f3_mul(ray.direction, distance));
		normal = s_normal(quartic, point);
		if ((t_ray_hit_records_builder_add(builder, (t_ray_hit_record){distance,
					normal, t_ray_material_from_computed(quartic.material),
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
