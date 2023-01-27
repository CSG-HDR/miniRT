/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ray_material_from_color.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:58:24 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2023/01/28 01:05:24 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_ray.h"

#include "t_map.h"

t_ray_material	t_ray_material_from_color(
	t_map_material material
)
{
	t_ray_material	result;

	result.color = (t_ray_material_color){
		T_RAY_MATERIAL_TYPE_COLOR,
		material,
	};
	return (result);
}
