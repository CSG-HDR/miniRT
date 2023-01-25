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

#include <stddef.h>

#include "ft_types.h"
#include "t_image.h"

t_err	minirt_image_to_mlx_image(
	t_image *param,
	t_minirt_mlx_image *image
)
{
	size_t	y;
	size_t	x;

	y = -1;
	while (++y < param->height)
	{
		x = -1;
		while (++x < param->width)
		{
			if (minirt_image_to_mlx_image_pixel(param, image, x, y))
			{
				return (true);
			}
		}
	}
	return (false);
}
