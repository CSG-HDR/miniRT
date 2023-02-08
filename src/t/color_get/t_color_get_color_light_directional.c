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
#include "t_f.h"
#include "t_f3.h"
#include "t_map.h"
#include "t_ray.h"

static t_f3	diffuse(const t_color_get_context *context, t_map_directional light)
{
	const t_map_normal		normal = light.direction;
	const t_f				factor
		= t_f_max((t_f)0, -t_f3_dot(normal, context->record.normal));
	const t_f3				color
		= t_f3_mul3(light.color, context->material.diffuse);
	const t_f3				result = t_f3_mul(color, factor);

	return (result);
}

static t_f3	reflection(const t_map_normal incidence, const t_map_normal normal)
{
	const t_map_normal	neg = t_f3_neg(normal);
	const t_f			length = -t_f3_dot(normal, incidence);
	const t_f3			sum = t_f3_mul(t_f3_mul(neg, 2), length);
	const t_f3			neg_direction = t_f3_sub(sum, incidence);
	const t_map_normal	result = t_f3_neg(t_f3_unit(neg_direction));

	return (result);
}

static t_f3	specular(
	const t_color_get_context *context,
	t_map_directional light
)
{
	const t_map_normal		normal = light.direction;
	const t_map_normal		reflection_normal
		= reflection(context->ray.direction, context->record.normal);
	const t_f				factor = t_f_pow(t_f_max((t_f)0, -t_f3_dot(normal,
					reflection_normal)), context->material.specular_lobe);
	const t_f3				result
		= t_f3_mul(t_f3_mul3(light.color, context->material.specular), factor);

	return (result);
}

t_err	t_color_get_color_light_directional(
	const t_color_get_context *context,
	t_map_directional light,
	t_f3 *out
)
{
	const t_map_position	real_point = t_f3_add(context->ray.origin,
			t_f3_mul(context->ray.direction, context->record.distance));
	const t_map_position	point = t_f3_add(real_point,
			t_f3_mul(context->record.normal, (t_f)T_F_EPSILON));
	const t_map_normal		normal = t_f3_neg(light.direction);
	t_ray_hit_records		records;

	if (t_ray_nearest_map(
			(t_ray){point, normal}, context->context->map, &records))
		return (true);
	if (records.hit_record_count)
		*out = (t_f3){(t_f)0, (t_f)0, (t_f)0};
	else
		*out = t_f3_add(diffuse(context, light), specular(context, light));
	t_ray_hit_records_free(records);
	return (false);
}
