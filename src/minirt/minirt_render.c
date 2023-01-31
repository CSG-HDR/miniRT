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
#include "t.h"
#include "t_color_get.h"
#include "t_f.h"
#include "t_f3.h"
#include "t_image.h"
#include "t_map.h"
#include "t_ray.h"

#define SS_RATE 2

static t_err	ss(const t_context *c, size_t x, size_t y, t_f3 *out)
{
	const t_f			f_x
		= (t_f)(c->map->viewport.start_x * SS_RATE + x)
		/ (c->map->viewport.width * SS_RATE - 1);
	const t_f			f_y
		= (t_f)(c->map->viewport.start_y * SS_RATE + y)
		/ (c->map->viewport.height * SS_RATE - 1);
	const t_ray			ray = t_ray_get(c->map, f_x, f_y);
	t_ray_hit_records	records;

	if (t_ray_nearest_map(ray, c->map, &records))
		return (true);
	if (!records.hit_record_count)
		*out = c->map->void_color;
	else
		*out = t_color_get_ray(
				c,
				records.hit_records[0].material,
				records.hit_records[0].x,
				records.hit_records[0].y);
	t_ray_hit_records_free(records);
	return (false);
}

// super sampling
static t_err	fill(void *context, size_t x, size_t y, t_f3 *out)
{
	const t_context	ctx = (t_context){
		((t_minirt *)context)->map, ((t_minirt *)context)->texture_manager};
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
			if (ss(&ctx, x * SS_RATE + i, y * SS_RATE + j, &tmp))
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
