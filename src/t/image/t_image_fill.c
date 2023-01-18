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

#include <stddef.h>

#include "wrap.h"
#include "t_f3.h"

t_err	t_image_fill(
	t_image *self,
	t_err (*fill)(void *context, size_t x, size_t y, t_f3 *out),
	void *context
)
{
	size_t	y;
	size_t	x;

	y = -1;
	while (++y < self->height)
	{
		x = -1;
		while (++x < self->width)
			if (fill(context, x, y, &self->extra[y * self->width + x]))
				return (true);
	}
	return (false);
}
