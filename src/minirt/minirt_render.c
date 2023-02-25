/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2023/02/25 12:35:43 by juwkim           ###   ########.fr       */
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

static t_err	ss(const t_context *c, size_t x, size_t y, t_f3 *out)
{
	const t_f			f_x
		= (t_f)(c->map->viewport.start_x * c->map->render_options.super_sampling
			+ x)
		/ (c->map->viewport.width * c->map->render_options.super_sampling - 1);
	const t_f			f_y
		= (t_f)(c->map->viewport.start_y * c->map->render_options.super_sampling
			+ y)
		/ (c->map->viewport.height * c->map->render_options.super_sampling - 1);
	const t_ray			ray = t_ray_get(c->map, f_x, f_y);
	t_ray_hit_records	records;
	t_err				result;

	if (t_ray_nearest_map(ray, c->map, &records))
		return (true);
	if (!records.hit_record_count)
	{
		*out = c->map->void_color;
		t_ray_hit_records_free(records);
		return (false);
	}
	result = t_color_get_color(c, ray, records.hit_records[0], out);
	t_ray_hit_records_free(records);
	*out = t_color_get_to_ldr(c, *out);
	return (result);
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
	while (++i < ctx.map->render_options.super_sampling)
	{
		j = -1;
		while (++j < ctx.map->render_options.super_sampling)
		{
			if (ss(&ctx, x * ctx.map->render_options.super_sampling + i,
					y * ctx.map->render_options.super_sampling + j, &tmp))
				return (true);
			acc = t_f3_add(acc, tmp);
		}
	}
	*out = t_f3_div(acc, ctx.map->render_options.super_sampling
			* ctx.map->render_options.super_sampling);
	return (false);
}

void	minirt_render(t_minirt *minirt)
{
	if (!minirt->rendered)
	{
		if (t_image_fill(minirt->tmp, fill, minirt))
			minirt_die("Error: failed to render scene\n");
		if (minirt_image_to_mlx_image(minirt->tmp, &minirt->image))
			minirt_die("Error: unrecognized mlx BPP\n");
		minirt->rendered = true;
	}
	mlx_put_image_to_window(
		minirt->mlx_context, minirt->mlx_window, minirt->mlx_image, 0, 0);
}
