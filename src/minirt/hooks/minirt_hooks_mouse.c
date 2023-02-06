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

#include "minirt_hooks.h"

#include "ft_types.h"
#include "t.h"
#include "t_f3.h"
#include "t_ray.h"
#include "t_color_get.h"

#include <stdlib.h>

#ifdef DEBUG

static t_f3	*unused(void)
{
	static t_f3	dummy;

	return (&dummy);
}

static t_err	debug_render_pixel(t_minirt *c, size_t x, size_t y)
{
	const t_f			f_x
		= (t_f)(c->map->viewport.start_x + x)
		/ (c->map->viewport.width - 1);
	const t_f			f_y
		= (t_f)(c->map->viewport.start_y + y)
		/ (c->map->viewport.height - 1);
	const t_ray			ray = t_ray_get(c->map, f_x, f_y);
	t_ray_hit_records	records;
	const t_context		context = {c->map, c->texture_manager};

	if (t_ray_nearest_map(ray, c->map, &records))
	{
		t_ray_hit_records_free(records);
		return (true);
	}
	if (records.hit_record_count
		&& t_color_get_color(&context, ray, records.hit_records[0], unused()))
	{
		t_ray_hit_records_free(records);
		return (true);
	}
	t_ray_hit_records_free(records);
	return (false);
}

int	minirt_hooks_mouse(int button, int x, int y, t_minirt *param)
{
	if (button == 1)
		if (debug_render_pixel(param, x, y))
			return (1);
	return (0);
}

#else

int	minirt_hooks_mouse(int button, int x, int y, t_minirt *param)
{
	(void)button;
	(void)x;
	(void)y;
	(void)param;
	return (0);
}

#endif
