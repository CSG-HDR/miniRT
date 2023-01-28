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

t_err	t_ray_constructive_difference(
	t_ray ray,
	t_map_difference difference,
	t_ray_hit_records *out
)
{
	t_ray_hit_records	from;
	t_ray_hit_records	subtract;

	if (t_ray_model(ray, difference.from, &from))
		return (true);
	if (t_ray_model(ray, difference.subtract, &subtract))
	{
		t_ray_hit_records_free(from);
		return (true);
	}
	if (t_ray_difference(from, subtract, out))
	{
		t_ray_hit_records_free(from);
		t_ray_hit_records_free(subtract);
		return (true);
	}
	t_ray_hit_records_free(from);
	t_ray_hit_records_free(subtract);
	return (false);
}
