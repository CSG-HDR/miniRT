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

t_image	*t_image_new(
	size_t width,
	size_t height,
	t_err (*fill)(void *context, size_t x, size_t y, t_f3 *out),
	void *context
)
{
	const size_t	size = sizeof(t_image) + sizeof(t_f3) * width * height;
	t_image *const	result = wrap_malloc(size);

	result->width = width;
	result->height = height;
	if (fill && t_image_fill(result, fill, context))
	{
		wrap_free(result);
		return (NULL);
	}
	return (result);
}
