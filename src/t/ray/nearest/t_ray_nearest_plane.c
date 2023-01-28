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

#include "ft_types.h"
#include "t_f.h"
#include "t_f3.h"
#include "t_map.h"

typedef struct s_plane
{
	t_f	a;
	t_f	b;
	t_f	c;
	t_f	d;
}	t_plane;

static t_plane	s_plane(t_map_plane plane)
{
	const t_f		a = plane.normal.x;
	const t_f		b = plane.normal.y;
	const t_f		c = plane.normal.z;
	const t_f3		p = plane.position;
	const t_plane	result = {
		a,
		b,
		c,
		0 - a * p.x - b * p.y - c * p.z
	};

	return (result);
}

/**
 * f(x, y, z) = ax + by + cz + d = 0
 * f(ray.position + ray.direction * distance) = 0
 * f(p+ut, q+vt, r+wt) = 0
 *
 * t = (pa + qb + rc) / (ua + vb + wc)
 */
static t_f	s_distance(t_plane p, t_ray r)
{
	return (
		(r.origin.x * p.a + r.origin.y * p.b + r.origin.z * p.c + p.d)
		/ (r.direction.x * p.a + r.direction.y * p.b + r.direction.z * p.c)
	);
}

t_err	t_ray_nearest_plane(
	t_ray ray,
	t_map_plane plane,
	t_ray_hit_records *out
)
{
	t_ray_hit_records_builder	*builder;
	const t_plane				p = s_plane(plane);
	const t_f					distance = s_distance(p, ray);

	if (t_ray_hit_records_builder_init(&builder))
		return (true);
	if ((distance > 0 && t_ray_hit_records_builder_add(
				builder, (t_ray_hit_record){distance, plane.normal,
				t_ray_material_from_computed(plane.material), true, 0, 0})
	) || t_ray_hit_records_builder_build(builder, out))
	{
		t_ray_hit_records_builder_free(builder);
		return (true);
	}
	t_ray_hit_records_builder_free(builder);
	return (false);
}
