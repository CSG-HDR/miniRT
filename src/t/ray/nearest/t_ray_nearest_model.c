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

t_err	t_ray_nearest_model(
	t_ray ray,
	t_map_model *model,
	t_ray_hit_records *out
)
{
	t_ray_hit_records	multiple;

	if (t_ray_model(ray, model, &multiple))
		return (true);
	if (t_ray_hit_records_copy_first(multiple, out))
	{
		t_ray_hit_records_free(multiple);
		return (true);
	}
	t_ray_hit_records_free(multiple);
	return (false);
}
