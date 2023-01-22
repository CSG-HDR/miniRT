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

typedef struct s_context
{
	size_t			offset;
	size_t			width;
	size_t			height;
	size_t			row_padding;
	size_t			row_size;
	size_t			whole_size;
	const uint8_t	*str;
}	t_context;

static t_err	fill(void *context, size_t x, size_t y, t_f3 *out)
{
	t_context *const	l = context;

	out->x = l->str[
		l->offset + l->row_size * (l->height - y - 1) + 3 * x + 2
	] / (t_f)255;
	out->y = l->str[
		l->offset + l->row_size * (l->height - y - 1) + 3 * x + 1
	] / (t_f)255;
	out->z = l->str[
		l->offset + l->row_size * (l->height - y - 1) + 3 * x + 0
	] / (t_f)255;
	return (false);
}

t_err	t_image_deserialize(const char *str, size_t length, t_image **out)
{
	t_context	l;

	if (length <= 54 || str[0] != 'B' || str[1] != 'M'
		|| *((uint16_t *)&str[28]) != 24 || *((uint32_t *)&str[30]) != 0)
		return (true);
	l.offset = *((uint32_t *)&str[10]);
	l.width = *((uint32_t *)&str[18]);
	l.height = *((uint32_t *)&str[22]);
	l.row_padding = (4 - (l.width * 3) % 4) % 4;
	l.row_size = l.width * 3 + l.row_padding;
	l.whole_size = l.row_size * l.height - l.row_padding;
	l.str = (uint8_t *)str;
	if (length < l.offset + l.whole_size)
		return (true);
	*out = t_image_new(l.width, l.height, fill, &l);
	if (!*out)
		return (true);
	return (false);
}
