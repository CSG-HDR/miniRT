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

#include "t_map_get.h"

#include "t.h"
#include "t_map.h"
#include "t_ray.h"

t_err	t_map_get(const t_context *context, t_ray ray, t_ray_hit_records *out)
{
	t_ray_hit_records	records;

	if (t_ray_nearest_planes(
			ray, context->map->planes, context->map->plane_count, &records))
		return (true);
	*out = records;
	return (false);
}
