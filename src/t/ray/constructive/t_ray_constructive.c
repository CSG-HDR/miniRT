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

t_err	t_ray_constructive(
	t_ray ray,
	t_map_constructive constructive,
	t_ray_hit_records *out
)
{
	if (*constructive.type == T_MAP_CONSTRUCTIVE_TYPE_UNION)
		return (t_ray_constructive_union(
				ray, constructive._union->_union, out));
	if (*constructive.type == T_MAP_CONSTRUCTIVE_TYPE_INTERSECTION)
		return (t_ray_constructive_intersection(
				ray, constructive.intersection->intersection, out));
	else
		return (t_ray_constructive_difference(
				ray, constructive.difference->difference, out));
}
