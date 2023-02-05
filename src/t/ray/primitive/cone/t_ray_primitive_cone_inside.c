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

#include <stdbool.h>

#include "ft_types.h"
#include "t_f3.h"
#include "t_map.h"
#include "t_ray.h"

t_err	t_ray_primitive_cone_inside(
	t_ray ray,
	t_map_cone cone,
	t_ray_hit_records_builder *builder
)
{
	t_f	x;
	t_f	y;
	t_f	r;

	if (0 > ray.origin.z || ray.origin.z > cone.size.z)
		return (false);
	x = ray.origin.x / cone.size.x;
	y = ray.origin.y / cone.size.y;
	r = 1 - (ray.origin.z / cone.size.z);
	return (
		(x * x) + (y * y) < (r * r)
		&& t_ray_hit_records_builder_add(
			builder,
			t_ray_default_hit_record(cone.material_side)
		)
	);
}
