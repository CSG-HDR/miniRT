/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongyle <seongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2023/01/22 20:00:08 by seongyle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "minirt_math.h"
#include "t_map.h"

void	minirt_render(t_minirt *minirt)
{
	// 아래 로직을 fill 함수로 분리
	unsigned long i;
	unsigned long j;
	t_f u;
	t_f v;
	t_map_material_color pixel_color;

	j = minirt->map->viewport.actual_height - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < minirt->map->viewport.actual_width - 1)
		{
			u = (t_f) i / (minirt->map->viewport.actual_width - 1);
			v = (t_f) j / (minirt->map->viewport.actual_height - 1);
			// TODO: camera와 u,v 를 이용해서 ray 생성해서 minirt구조체에 업데이트
			pixel_color = minirt->map->void_color;
			// TODO: ray 정보를 이용하여 pixel_color 업데이트
			++i;
		}
	}
	--j;
}
