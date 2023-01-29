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
#include "t_map.h"

static t_err	planes_and_quadrics(
	t_ray ray,
	t_map *map,
	t_ray_hit_records *out
)
{
	t_ray_hit_records	planes;
	t_ray_hit_records	quadrics;
	t_ray_hit_records	result;

	if (t_ray_nearest_planes(ray, map->planes, map->plane_count, &planes))
		return (true);
	if (t_ray_nearest_quadrics(
			ray, map->quadrics, map->quadric_count, &quadrics))
	{
		t_ray_hit_records_free(planes);
		return (true);
	}
	if (t_ray_nearest(planes, quadrics, &result))
	{
		t_ray_hit_records_free(planes);
		t_ray_hit_records_free(quadrics);
		return (true);
	}
	t_ray_hit_records_free(planes);
	t_ray_hit_records_free(quadrics);
	*out = result;
	return (false);
}

t_err	t_ray_nearest_map(
	t_ray ray,
	t_map *map,
	t_ray_hit_records *out
)
{
	t_ray_hit_records	models;
	t_ray_hit_records	and;
	t_ray_hit_records	result;

	if (t_ray_nearest_models(ray, map->models, map->model_count, &models))
		return (true);
	if (planes_and_quadrics(ray, map, &and))
	{
		t_ray_hit_records_free(models);
		return (true);
	}
	if (t_ray_nearest(models, and, &result))
	{
		t_ray_hit_records_free(models);
		t_ray_hit_records_free(and);
		return (true);
	}
	t_ray_hit_records_free(models);
	t_ray_hit_records_free(and);
	*out = result;
	return (false);
}
