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
#include "t_image.h"
#include "t_map.h"
#include "wrap.h"
#include <stdbool.h>

static t_err	fill(void *context, size_t x, size_t y, t_f3 *out)
{
	t_minirt *const	minirt = (t_minirt *)context;

	(void)x;
	(void)y;
	*out = minirt->map->void_color;
	return (false);
}


void	minirt_render(t_minirt *minirt)
{
	const size_t	width = minirt->map->viewport.actual_width;
	const size_t	height = minirt->map->viewport.actual_height;
	t_image *const	pre_image = t_image_new(width, height, fill, minirt);

	t_image_print_as_bmp(pre_image);
	wrap_free(pre_image);
}
