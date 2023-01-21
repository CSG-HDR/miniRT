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

#include "t_map_free.h"

#include "wrap.h"
#include "t_map.h"
#include "t_map_free.h"

void	t_map_free_constructive(t_map_constructive value)
{
	if (*value.type == T_MAP_CONSTRUCTIVE_UNION)
	{
		t_map_free_union(value._union->_union);
		wrap_free(value._union);
	}
	else if (*value.type == T_MAP_CONSTRUCTIVE_INTERSECTION)
	{
		t_map_free_intersection(value.intersection->intersection);
		wrap_free(value.intersection);
	}
	else
	{
		t_map_free_difference(value.difference->difference);
		wrap_free(value.difference);
	}
}
