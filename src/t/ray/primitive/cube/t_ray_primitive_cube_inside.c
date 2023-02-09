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

#include "t_ray_primitive_cube.h"

#include <stdbool.h>

#include "ft_types.h"
#include "t_f3.h"
#include "t_map.h"
#include "t_ray.h"

t_err	t_ray_primitive_cube_inside(
	t_ray ray,
	t_map_cube cube,
	t_ray_hit_records_builder *builder
)
{
	const t_f	x = ray.origin.x / cube.size.x;
	const t_f	y = ray.origin.y / cube.size.y;
	const t_f	z = ray.origin.z / cube.size.z;

	return (
		true
		&& x > 0
		&& y > 0
		&& z > 0
		&& x < 1
		&& y < 1
		&& z < 1
		&& t_ray_hit_records_builder_add(
			builder,
			t_ray_default_hit_record(cube.material_top)
		)
	);
}
