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

#include "t_texture_manager.h"

#include "t_map.h"

t_err	t_texture_manager_preload_constructive(
	t_texture_manager *self,
	t_map_constructive constructive
)
{
	if (*constructive.type == T_MAP_CONSTRUCTIVE_TYPE_UNION)
		return (
			t_texture_manager_preload_union(
				self,
				constructive._union->_union
			)
		);
	if (*constructive.type == T_MAP_CONSTRUCTIVE_TYPE_INTERSECTION)
		return (
			t_texture_manager_preload_intersection(
				self,
				constructive.intersection->intersection
			)
		);
	else
		return (
			t_texture_manager_preload_difference(
				self,
				constructive.difference->difference
			)
		);
}
