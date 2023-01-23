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

#include "t_color_get.h"

#include <stdbool.h>

#include "t.h"
#include "t_f.h"
#include "t_f3.h"
#include "t_image.h"
#include "t_map.h"
#include "t_texture_manager.h"

static size_t	nearest_texel_position(size_t size, t_f coord, bool mirror)
{
	bool	negate;
	size_t	result;

	negate = false;
	result = (size_t)(coord + 0.5);
	if (coord < 0)
	{
		result = (size_t)(-coord + 0.5);
		negate = !mirror;
	}
	if (mirror && (result / size) % 2)
		negate = !negate;
	result %= size;
	if (negate)
		result = size - result - 1;
	return (result);
}

static t_f3	nearest(const t_image *image, t_f u, t_f v, bool mirror)
{
	const size_t	x = nearest_texel_position(image->width, u, mirror);
	const size_t	y = nearest_texel_position(image->height, v, mirror);

	return (image->extra[y * image->width + x]);
}

// TODO: implement linear
static t_f3	linear(const t_image *image, t_f u, t_f v, bool mirror)
{
	return (nearest(image, u, v, mirror));
}

t_f3	t_color_get_texture(
	t_context *context,
	t_map_texture texture,
	t_f x,
	t_f y
)
{
	const t_image *const	image
		= t_texture_manager_get(context->text_manager, texture.src);
	const t_f				u = x / texture.width * image->width;
	const t_f				v = y / texture.height * image->height;

	if (texture.nearest)
		return (nearest(image, u, v, texture.mirror));
	else
		return (linear(image, u, v, texture.mirror));
}
