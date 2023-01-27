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

#define SS_RATE 2

// print normal
static t_err	ss(t_map *m, size_t x, size_t y, t_f3 *out)
{
	const t_f	f_x
		= (t_f)(m->viewport.start_x * SS_RATE + x)
		/ (m->viewport.width * SS_RATE - 1);
	const t_f	f_y
		= (t_f)(m->viewport.start_y * SS_RATE + y)
		/ (m->viewport.height * SS_RATE - 1);
	const t_ray	ray = t_ray_get(m, f_x, f_y);

	out->x = ray.direction.x / 2 + (t_f)0.5;
	if (ray.direction.x < 0)
		out->x = 1;
	out->y = ray.direction.y / 2 + (t_f)0.5;
	out->z = ray.direction.z / 2 + (t_f)0.5;
	if (ray.direction.z < 0)
		out->z = 1;
	return (false);
}

// super sampling
static t_err	fill(void *context, size_t x, size_t y, t_f3 *out)
{
	t_minirt *const	minirt = context;
	size_t			j;
	size_t			i;
	t_f3			acc;
	t_f3			tmp;

	acc = (t_f3){0, 0, 0};
	i = -1;
	while (++i < SS_RATE)
	{
		j = -1;
		while (++j < SS_RATE)
		{
			if (ss(minirt->map, x * SS_RATE + i, y * SS_RATE + j, &tmp))
				return (true);
			acc = t_f3_add(acc, tmp);
		}
	}
	*out = t_f3_div(acc, SS_RATE * SS_RATE);
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
