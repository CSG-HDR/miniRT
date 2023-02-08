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

#include "ft_types.h"
#include "t.h"
#include "t_f3.h"
#include "t_map.h"
#include "t_ray.h"

t_err	t_color_get_color(
	const t_context *context,
	t_ray ray,
	t_ray_hit_record record,
	t_f3 *out
)
{
	const t_map_color_material	material = t_color_get_ray_material(
			context, record.material, record.x, record.y);
	const t_color_get_context	c = {context, material, ray, record};
	t_f3						tmp;
	size_t						i;

	*out = t_f3_mul3(material.ambient, context->map->ambient_light);
	i = -1;
	while (++i < context->map->light_count)
	{
		if (t_color_get_color_light(
				&c, context->map->lights[i], &tmp))
			return (true);
		*out = t_f3_add(*out, tmp);
	}
	return (false);
}
