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
#include "t_f.h"
#include "t_f3.h"
#include "t_image.h"
#include "t_map.h"
#include "t_ray.h"
#include "wrap.h"

static t_map_normal	get_normal(t_minirt *minirt, t_f f_x, t_f f_y)
{
	const t_map_rotation	rotation = minirt->map->camera.rotation;
	const t_f				w = t_f_sec(minirt->map->camera.fov_x / (t_f)2);
	const t_f				h = t_f_sec(minirt->map->camera.fov_y / (t_f)2);
	const t_f				x = w * (2 * f_x - (t_f)0.5);
	const t_f				y = h * (2 * f_y - (t_f)0.5);

	return (t_f3_rotate(t_f3_unit((t_f3){x, 1, -y}), rotation));
}

// print normal
static t_err	fill(void *context, size_t x, size_t y, t_f3 *out)
{
	t_minirt *const		minirt = (t_minirt *)context;
	const t_f			f_x = (t_f)(minirt->map->viewport.start_x + x)
		/ (minirt->map->viewport.width - 1);
	const t_f			f_y = (t_f)(minirt->map->viewport.start_y + y)
		/ (minirt->map->viewport.height - 1);
	const t_map_normal	normal = get_normal(minirt, f_x, f_y);
	const t_ray			ray = (t_ray){minirt->map->camera.position, normal};

	(void)ray;
	out->x = normal.x / 2 + (t_f)0.5;
	out->y = normal.y / 2 + (t_f)0.5;
	out->z = normal.z / 2 + (t_f)0.5;
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
