/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ray_material_from_computed.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:58:24 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2023/01/28 01:05:05 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_ray.h"

#include "t_map.h"

t_ray_material	t_ray_material_from_computed(
	t_map_color_material material
)
{
	t_ray_material	result;

	result.computed = (t_ray_material_computed){
		T_RAY_MATERIAL_TYPE_COMPUTED,
		material,
	};
	return (result);
}
