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
#include <limits.h>

#include "ft_types.h"
#include "t_f.h"
#include "t_f3.h"
#include "t_image.h"

static void	render_pixel_32le(
	t_image *image,
	unsigned char *address_of_pixel_data,
	size_t x,
	size_t y
)
{
	const t_f3	color = image->extra[y * image->width + x];

	address_of_pixel_data[0] = (t_f)(color.z * 255);
	address_of_pixel_data[1] = (t_f)(color.y * 255);
	address_of_pixel_data[2] = (t_f)(color.x * 255);
	address_of_pixel_data[3] = 0;
}

static void	render_pixel_32be(
	t_image *image,
	unsigned char *address_of_pixel_data,
	size_t x,
	size_t y
)
{
	const t_f3	color = image->extra[y * image->width + x];

	address_of_pixel_data[0] = 0;
	address_of_pixel_data[1] = (t_f)(color.x * 255);
	address_of_pixel_data[2] = (t_f)(color.y * 255);
	address_of_pixel_data[3] = (t_f)(color.z * 255);
}

static void	render_pixel_24le(
	t_image *image,
	unsigned char *address_of_pixel_data,
	size_t x,
	size_t y
)
{
	const t_f3	color = image->extra[y * image->width + x];

	address_of_pixel_data[0] = (t_f)(color.z * 255);
	address_of_pixel_data[1] = (t_f)(color.y * 255);
	address_of_pixel_data[2] = (t_f)(color.x * 255);
}

static void	render_pixel_24be(
	t_image *image,
	unsigned char *address_of_pixel_data,
	size_t x,
	size_t y
)
{
	const t_f3	color = image->extra[y * image->width + x];

	address_of_pixel_data[0] = (t_f)(color.x * 255);
	address_of_pixel_data[1] = (t_f)(color.y * 255);
	address_of_pixel_data[2] = (t_f)(color.z * 255);
}

t_err	minirt_image_to_mlx_image_pixel(
	t_image *param,
	t_minirt_mlx_image *image,
	size_t x,
	size_t y
)
{
	const size_t	index
		= image->size_of_line * y + image->bits_per_pixel / 8 * x;

	if (image->bits_per_pixel == 32 && image->endian == 0 && CHAR_BIT == 8)
		render_pixel_32le(param, &image->data[index], x, y);
	else if (image->bits_per_pixel == 32 && image->endian == 1 && CHAR_BIT == 8)
		render_pixel_32be(param, &image->data[index], x, y);
	else if (image->bits_per_pixel == 24 && image->endian == 0 && CHAR_BIT == 8)
		render_pixel_24le(param, &image->data[index], x, y);
	else if (image->bits_per_pixel == 24 && image->endian == 1 && CHAR_BIT == 8)
		render_pixel_24be(param, &image->data[index], x, y);
	else
		return (true);
	return (false);
}
