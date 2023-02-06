/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_color_get_ray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2023/02/06 21:52:29 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_color_get.h"

#include "t_map.h"
#include "t_ray.h"

t_map_color_material	t_color_get_ray_material(
	const t_context *context,
	t_ray_material color,
	t_f x,
	t_f y
)
{
	if (color.type == T_RAY_MATERIAL_TYPE_COMPUTED)
		return (color.computed.computed);
	else
		return ((t_map_color_material){
			t_color_get(context, color.color.color.ambient, x, y),
			t_color_get(context, color.color.color.diffuse, x, y),
			t_color_get(context, color.color.color.specular, x, y),
			color.color.color.specular_lobe,
		});
}
