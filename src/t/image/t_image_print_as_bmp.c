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

static t_err	print_header(t_image *self, size_t *out_row_padding)
{
	const size_t	row_padding = (4 - (self->width * 3) % 4) % 4;
	const size_t	row_size = self->width * 3 + row_padding;
	const size_t	whole_size = row_size * self->height;

	*out_row_padding = row_padding;
	return (
		false
		|| ft_io_write(STDOUT_FILENO, "BM", 2)
		|| ft_io_le_write_u32(STDOUT_FILENO, (uint32_t)whole_size + 54)
		|| ft_io_le_write_u32(STDOUT_FILENO, 0)
		|| ft_io_le_write_u32(STDOUT_FILENO, 54)
		|| ft_io_le_write_u32(STDOUT_FILENO, 40)
		|| ft_io_le_write_u32(STDOUT_FILENO, (uint32_t)self->width)
		|| ft_io_le_write_u32(STDOUT_FILENO, (uint32_t)self->height)
		|| ft_io_le_write_u16(STDOUT_FILENO, 1)
		|| ft_io_le_write_u16(STDOUT_FILENO, 24)
		|| ft_io_le_write_u32(STDOUT_FILENO, 0)
		|| ft_io_le_write_u32(STDOUT_FILENO, (uint32_t)whole_size)
		|| ft_io_le_write_u32(STDOUT_FILENO, 0)
		|| ft_io_le_write_u32(STDOUT_FILENO, 0)
		|| ft_io_le_write_u32(STDOUT_FILENO, 256)
		|| ft_io_le_write_u32(STDOUT_FILENO, 0)
	);
}

t_err	t_image_print_as_bmp(t_image *self)
{
	size_t	row_padding;
	size_t	y;
	size_t	x;

	if (print_header(self, &row_padding))
		return (true);
	y = self->height;
	while (y--)
	{
		x = -1;
		while (++x < self->width)
			if (
				false
				|| ft_io_le_write_u8(STDOUT_FILENO,
					self->extra[self->width * y + x].z * 255)
				|| ft_io_le_write_u8(STDOUT_FILENO,
					self->extra[self->width * y + x].y * 255)
				|| ft_io_le_write_u8(STDOUT_FILENO,
					self->extra[self->width * y + x].x * 255)
			)
				return (true);
		if (row_padding && ft_io_write(STDOUT_FILENO, "\0\0\0", row_padding))
			return (true);
	}
	return (false);
}
