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

#include "t.h"
#include "t_f3.h"
#include "t_map.h"

t_f3	t_color_get_blend(
	t_context *context,
	t_map_blend blend,
	t_f x,
	t_f y
)
{
	if (blend.type == T_MAP_BLEND_TYPE_ADD)
		return (t_color_get_add(context, blend.add, x, y));
	else if (blend.type == T_MAP_BLEND_TYPE_MULTIPLY)
		return (t_color_get_multiply(context, blend.multiply, x, y));
	else if (blend.type == T_MAP_BLEND_TYPE_MAXIMUM)
		return (t_color_get_maximum(context, blend.maximum, x, y));
	else if (blend.type == T_MAP_BLEND_TYPE_MINIMUM)
		return (t_color_get_minimum(context, blend.minimum, x, y));
	else
		return (t_color_get_subtract(context, blend.subtract, x, y));
}
