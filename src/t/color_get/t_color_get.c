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

#include "t_color_get.h"

#include "t_map.h"

t_f3	t_color_get(const t_context *context, t_map_color *color, t_f x, t_f y)
{
	if (color->type == T_MAP_COLOR_TYPE_COLOR)
		return (color->color.color);
	if (color->type == T_MAP_COLOR_TYPE_TEXTURE)
		return (t_color_get_texture(context, color->texture.texture, x, y));
	else
		return (t_color_get_blend(context, color->blend.blend, x, y));
}
