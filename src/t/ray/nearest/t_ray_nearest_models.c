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

t_err	t_ray_nearest_models(
	t_ray ray,
	t_map_model **models,
	size_t model_count,
	t_ray_hit_records *out
)
{
	t_ray_hit_records	nearest;
	t_ray_hit_records	current;
	t_ray_hit_records	tmp;

	nearest = (t_ray_hit_records){0, NULL};
	while (model_count--)
	{
		tmp = nearest;
		if (t_ray_nearest_model(ray, models[model_count], &current))
		{
			t_ray_hit_records_free(tmp);
			return (true);
		}
		if (t_ray_nearest(tmp, current, &nearest))
		{
			t_ray_hit_records_free(tmp);
			t_ray_hit_records_free(current);
			return (true);
		}
		t_ray_hit_records_free(tmp);
		t_ray_hit_records_free(current);
	}
	*out = nearest;
	return (false);
}
