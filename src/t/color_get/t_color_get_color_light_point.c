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
#include "t_f3.h"
#include "t_map.h"

t_err	t_color_get_color_light_point(
	const t_color_get_context *context,
	t_map_point light,
	t_f3 *out
)
{
	const t_map_position	point = t_f3_add(context->ray.origin,
			t_f3_mul(context->ray.direction, context->record.distance));
	const t_map_normal		normal = t_f3_unit(
			t_f3_sub(light.position, point));
	const t_f				factor = t_f3_dot(normal, context->ray.direction);
	const t_f3				color
		= t_f3_mul(t_f3_mul3(light.color, context->material.diffuse), factor);

	*out = color;
	return (false);
}
