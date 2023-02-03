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

#include "t_map.h"

t_ray	t_ray_preprocess(
	t_ray ray,
	t_map_position position,
	t_map_rotation rotation
)
{
	const t_map_position	rotated = t_f3_rotate_reverse_from_origin(
			ray.origin, position, rotation);
	const t_map_position	moved = t_f3_sub(rotated, position);
	const t_map_normal		direction
		= t_f3_rotate_reverse(ray.direction, rotation);

	return ((t_ray){moved, direction});
}
