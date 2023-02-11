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

#include "ft_types.h"
#include "t_f3.h"
#include "t_map.h"

t_err	t_color_get_color_light(
	const t_color_get_context *context,
	t_map_light light,
	t_f3 *out
)
{
	if (*light.type == T_MAP_LIGHT_TYPE_POINT)
		return (t_color_get_color_light_point(
				context, light.point->point, out));
	else
		return (t_color_get_color_light_directional(
				context, light.directional->directional, out));
}
