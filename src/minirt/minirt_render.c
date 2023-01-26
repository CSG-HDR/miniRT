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
#include <stdbool.h>

#include "mlx.h"
#include "t_image.h"
#include "t_map.h"
#include "wrap.h"

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
	if (t_image_fill(minirt->tmp, fill, minirt))
		minirt_die("Error: failed to render scene\n");
	if (minirt_image_to_mlx_image(minirt->tmp, &minirt->image))
		minirt_die("Error: unrecognized mlx BPP\n");
	mlx_put_image_to_window(
		minirt->mlx_context, minirt->mlx_window, minirt->mlx_image, 0, 0);
}
