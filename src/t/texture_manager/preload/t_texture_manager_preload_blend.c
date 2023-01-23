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

t_err	t_texture_manager_preload_blend(
	t_texture_manager *self,
	t_map_blend blend
)
{
	if (blend.type == T_MAP_BLEND_TYPE_ADD)
		return (t_texture_manager_preload_blend_add(
				self, blend.add));
	if (blend.type == T_MAP_BLEND_TYPE_MULTIPLY)
		return (t_texture_manager_preload_blend_multiply(
				self, blend.multiply));
	if (blend.type == T_MAP_BLEND_TYPE_MAXIMUM)
		return (t_texture_manager_preload_blend_maximum(
				self, blend.maximum));
	if (blend.type == T_MAP_BLEND_TYPE_MINIMUM)
		return (t_texture_manager_preload_blend_minimum(
				self, blend.minimum));
	else
		return (t_texture_manager_preload_blend_subtract(
				self, blend.subtract));
}
