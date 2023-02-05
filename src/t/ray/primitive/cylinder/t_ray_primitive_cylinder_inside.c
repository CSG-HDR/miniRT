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

#include <stdbool.h>

#include "ft_types.h"
#include "t_f3.h"
#include "t_map.h"
#include "t_ray.h"

t_err	t_ray_primitive_cylinder_inside(
	t_ray ray,
	t_map_cylinder cylinder,
	t_ray_hit_records_builder *builder
)
{
	t_f	x;
	t_f	y;

	if (0 > ray.origin.z || ray.origin.z > cylinder.size.z)
		return (false);
	x = ray.origin.x / cylinder.size.x;
	y = ray.origin.y / cylinder.size.y;
	return (
		(x * x) + (y * y) < 1
		&& t_ray_hit_records_builder_add(
			builder,
			t_ray_default_hit_record(cylinder.material_side)
		)
	);
}
