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

t_err	t_texture_manager_preload_color(
	t_texture_manager *self,
	t_map_color *color
)
{
	if (color->type == T_MAP_COLOR_TYPE_TEXTURE)
		return (
			t_texture_manager_preload_texture(
				self,
				color->texture.texture
			)
		);
	if (color->type == T_MAP_COLOR_TYPE_BLEND)
		return (
			t_texture_manager_preload_blend(
				self,
				color->blend.blend
			)
		);
	else
		return (false);
}
