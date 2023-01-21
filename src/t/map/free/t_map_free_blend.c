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

#include "t_map.h"

void	t_map_free_blend(t_map_blend value)
{
	if (value.type == T_MAP_BLEND_TYPE_ADD)
		t_map_free_blend_add(value.add);
	if (value.type == T_MAP_BLEND_TYPE_MULTIPLY)
		t_map_free_blend_multiply(value.multiply);
	if (value.type == T_MAP_BLEND_TYPE_MAXIMUM)
		t_map_free_blend_maximum(value.maximum);
	if (value.type == T_MAP_BLEND_TYPE_MINIMUM)
		t_map_free_blend_minimum(value.minimum);
	else
		t_map_free_blend_subtract(value.subtract);
}
