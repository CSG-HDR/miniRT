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

# include "t_image.h"

# include <stdio.h>
# include <stddef.h>
# include <stdint.h>

static t_err	put_u32(uint32_t i)
{
	const uint32_t		test = 42;
	const char *const	result = (const char *)&i;

	if (*((char *)&test))
	{
		return (
			printf(
				"%c%c%c%c",
				result[0],
				result[1],
				result[2],
				result[3]
			) < 0
		);
	}
	return (
		printf(
			"%c%c%c%c",
			result[3],
			result[2],
			result[1],
			result[0]
		) < 0
	);
}

static t_err	put_u16(uint16_t i)
{
	const uint16_t		test = 42;
	const char *const	result = (const char *)&i;

	if (*((char *)&test))
	{
		return (
			printf(
				"%c%c",
				result[0],
				result[1]
			) < 0
		);
	}
	return (
		printf(
			"%c%c",
			result[1],
			result[0]
		) < 0
	);
}

static t_err	print_header(t_image *self, size_t *out_row_padding)
{
	const size_t	row_padding = (4 - (self->width * 3) % 4) % 4;
	const size_t	row_size = self->width * 3 + row_padding;
	const size_t	whole_size = row_size * self->height;

	*out_row_padding = row_padding;
	return (
		false
		|| printf("BM") < 0
		|| put_u32((uint32_t)whole_size + 54)
		|| put_u32(0)
		|| put_u32(54)
		|| put_u32(40)
		|| put_u32((uint32_t)self->width)
		|| put_u32((uint32_t)self->height)
		|| put_u16(1)
		|| put_u16(24)
		|| put_u32(0)
		|| put_u32((uint32_t)whole_size)
		|| put_u32(0)
		|| put_u32(0)
		|| put_u32(256)
		|| put_u32(0)
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
			if (printf("%c%c%c",
					(unsigned char)(self->extra[self->width * y + x].z * 255),
					(unsigned char)(self->extra[self->width * y + x].y * 255),
					(unsigned char)(self->extra[self->width * y + x].x * 255))
				< 0)
				return (true);
		x = -1;
		while (++x < row_padding)
			if (printf("%c", '\0') < 0)
				return (true);
	}
	return (false);
}
