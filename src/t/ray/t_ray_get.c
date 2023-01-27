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

static t_map_normal	get_normal(t_map *map, t_f f_x, t_f f_y)
{
	const t_map_rotation	rotation = map->camera.rotation;
	const t_f				w = t_f_tan(map->camera.fov_x / (t_f)2);
	const t_f				h = t_f_tan(map->camera.fov_y / (t_f)2);
	const t_f				x = w * (2 * (f_x - (t_f)0.5));
	const t_f				y = h * (2 * (f_y - (t_f)0.5));

	return (t_f3_rotate(t_f3_unit((t_f3){x, 1, -y}), rotation));
}

t_ray	t_ray_get(t_map *map, t_f x, t_f y)
{
	return ((t_ray){map->camera.position, get_normal(map, x, y)});
}
