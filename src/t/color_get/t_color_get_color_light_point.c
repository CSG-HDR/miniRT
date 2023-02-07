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

static t_f3	diffuse(const t_color_get_context *context, t_map_point light)
{
	const t_map_position	point = t_f3_add(context->ray.origin,
			t_f3_mul(context->ray.direction, context->record.distance));
	const t_map_normal		normal = t_f3_unit(t_f3_sub(light.position, point));
	const t_f				factor
		= t_f3_dot(normal, t_f3_neg(context->ray.direction));
	const t_f3				color
		= t_f3_mul3(light.color, context->material.diffuse);
	const t_f3				result = t_f3_mul(color, factor);

	return (result);
}

// TODO: fix
static t_f3	reflection(const t_map_normal incidence, const t_map_normal normal)
{
	t_map_normal	neg;
	t_map_normal	direction;

	neg = t_f3_neg(normal);
	direction = t_f3_sub(t_f3_mul(neg, 2), incidence);
	return (t_f3_neg(t_f3_unit(direction)));
}

static t_f3	specular(const t_color_get_context *context, t_map_point light)
{
	const t_map_position	point = t_f3_add(context->ray.origin,
			t_f3_mul(context->ray.direction, context->record.distance));
	const t_map_normal		normal
		= t_f3_unit(t_f3_sub(point, light.position));
	const t_map_normal		reflection_normal
		= reflection(context->ray.direction, context->record.normal);
	const t_f				factor = t_f_pow(t_f3_dot(normal,
				reflection_normal), context->material.specular_lobe);
	const t_f3				result
		= t_f3_mul(t_f3_mul3(light.color, context->material.specular), factor);

	return (result);
}

static t_f	factor(t_map_position point, t_map_point light)
{
	t_f	distance;

	if (!light.has_range)
		return ((t_f)1);
	distance = t_f3_length(t_f3_sub(point, light.position));
	if (distance > light.range)
		return ((t_f)0);
	return (1 - (distance / light.range));
}

t_err	t_color_get_color_light_point(
	const t_color_get_context *context,
	t_map_point light,
	t_f3 *out
)
{
	const t_map_position	real_point = t_f3_add(context->ray.origin,
			t_f3_mul(context->ray.direction, context->record.distance));
	const t_map_position	point = t_f3_add(real_point,
			t_f3_mul(context->record.normal, (t_f)T_F_EPSILON));
	const t_map_normal		normal = t_f3_unit(t_f3_sub(light.position, point));
	const t_f				f = factor(real_point, light);
	t_ray_hit_records		records;

	if (!f)
	{
		*out = (t_f3){(t_f)0, (t_f)0, (t_f)0};
		return (false);
	}
	if (t_ray_nearest_map(
			(t_ray){point, normal}, context->context->map, &records))
		return (true);
	if (!f || (records.hit_record_count && records.hit_records[0].distance
			< t_f3_length(t_f3_sub(light.position, point))))
		*out = (t_f3){(t_f)0, (t_f)0, (t_f)0};
	else
		*out = t_f3_mul(t_f3_add(
					diffuse(context, light), specular(context, light)), f);
	t_ray_hit_records_free(records);
	return (false);
}
