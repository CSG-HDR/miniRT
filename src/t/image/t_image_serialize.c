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

#include "t_image.h"

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <unistd.h>

#include "ft_io.h"
#include "wrap.h"

static void	fill_header(t_image *self, char *result)
{
	const size_t	row_padding = (4 - (self->width * 3) % 4) % 4;
	const size_t	row_size = self->width * 3 + row_padding;
	const size_t	whole_size = row_size * self->height;

	result[0] = 'B';
	result[1] = 'M';
	*((uint32_t *)(result + 2)) = ft_io_le_convert_u32(54 + whole_size);
	*((uint32_t *)(result + 6)) = 0;
	*((uint32_t *)(result + 10)) = 54;
	*((uint32_t *)(result + 14)) = 40;
	*((uint32_t *)(result + 18)) = self->width;
	*((uint32_t *)(result + 22)) = self->height;
	*((uint16_t *)(result + 26)) = 1;
	*((uint16_t *)(result + 28)) = 24;
	*((uint32_t *)(result + 30)) = 0;
	*((uint32_t *)(result + 34)) = whole_size;
	*((uint32_t *)(result + 38)) = 0;
	*((uint32_t *)(result + 42)) = 0;
	*((uint32_t *)(result + 46)) = 256;
	*((uint32_t *)(result + 50)) = 0;
}

static void	fill_body(t_image *self, char *result)
{
	const size_t	row_padding = (4 - (self->width * 3) % 4) % 4;
	size_t			offset;
	size_t			y;
	size_t			x;
	size_t			i;

	offset = 0;
	y = self->height;
	while (y--)
	{
		x = -1;
		while (++x < self->width)
		{
			result[offset++]
				= ft_io_le_convert_u8(self->extra[self->width * y + x].z * 255);
			result[offset++]
				= ft_io_le_convert_u8(self->extra[self->width * y + x].y * 255);
			result[offset++]
				= ft_io_le_convert_u8(self->extra[self->width * y + x].x * 255);
		}
		i = -1;
		while (++i < row_padding)
			result[offset++] = 0;
	}
}

t_err	t_image_serialize(t_image *self, char **out, size_t *out_length)
{
	const size_t	row_padding = (4 - (self->width * 3) % 4) % 4;
	const size_t	row_size = self->width * 3 + row_padding;
	const size_t	whole_size = row_size * self->height;
	const size_t	length = 54 + whole_size;
	char *const		result = wrap_malloc(length);

	if (!result)
		return (true);
	fill_header(self, result);
	fill_body(self, result + 54);
	*out_length = length;
	*out = result;
	return (false);
}
