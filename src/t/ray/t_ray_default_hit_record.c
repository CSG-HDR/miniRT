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

#include "t_map.h"

t_ray_hit_record	t_ray_default_hit_record(t_map_material material)
{
	const t_map_normal	fallback_normal = {0, 0, 1};

	return ((t_ray_hit_record){
		0,
		fallback_normal,
		t_ray_material_from_color(material),
		true,
		0,
		0,
	});
}
