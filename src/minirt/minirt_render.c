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

#include "minirt.h"
#include "minirt_math.h"
#include "t_image.h"
#include "t_map.h"
#include "wrap.h"
#include <stdbool.h>

static t_err minirt_render_fill_image(void *context, size_t x, size_t y, t_f3 *out)
{
	const t_minirt* minirt = (t_minirt *) context;
	t_map_material_color* pre_image = out;
	const size_t	width = x;
	const size_t	height = y;
	// 아래 로직을 fill 함수로 분리
	size_t i;
	size_t j;

	t_map_material_color pixel_color;

	j = height - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < width - 1)
		{
			// TODO: camera와 u,v 를 이용해서 ray 생성해서 minirt구조체에 업데이트
			pixel_color = minirt->map->void_color;
			pre_image = &pixel_color;
			pre_image++;
			// TODO: ray 정보를 이용하여 pixel_color 업데이트
			++i;
		}
	}
	--j;
	return (false);
}


void	minirt_render(t_minirt *minirt)
{
	const size_t	width = minirt->map->viewport.actual_width;
	const size_t	height = minirt->map->viewport.actual_height;

	t_image *const	pre_image = t_image_new(width, height, minirt_render_fill_image, minirt);
	
	if (!pre_image)
	{
		// TODO: error처리 어떻게 할지 합의 필요
		// error 처리
		// error 처리 
	}
	t_image_print_as_bmp(pre_image);
	wrap_free(pre_image);
	// TODO:HDR랜더링
}
