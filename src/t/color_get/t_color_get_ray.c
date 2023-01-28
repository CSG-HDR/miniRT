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
#include "t_ray.h"

// TODO: lighting
t_f3	t_color_get_ray(
	const t_context *context,
	t_ray_material color,
	t_f x,
	t_f y
)
{
	if (color.type == T_RAY_MATERIAL_TYPE_COMPUTED)
		return (color.computed.computed.ambient);
	else
		return (t_color_get(context, color.color.color.ambient, x, y));
}
