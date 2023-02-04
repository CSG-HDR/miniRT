/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ray_primitive_cone.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongyle <seongyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2023/02/04 20:05:53 by seongyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_ray.h"

#include "ft_types.h"
#include "t_map.h"
#include "t_ray_primitive_cone.h"

static t_err	append_records(
	t_ray ray,
	t_map_cone cone,
	t_ray_hit_records_builder *builder
)
{
	return (
		false
		|| t_ray_primitive_cone_side(ray, cone, builder)
		|| t_ray_primitive_cone_bottom(ray, cone, builder)
	);
}

typedef struct s_locals
{
	t_ray_hit_records_builder	*builder;
	t_err						result;
	t_ray						preprocessed;
	size_t						i;
}	t_locals;

t_err	t_ray_primitive_cone(
	t_ray ray,
	t_map_cone cone,
	t_ray_hit_records *out
)
{
	t_locals	l;

	l.preprocessed = t_ray_preprocess(ray, cone.position, cone.rotation);
	if (t_ray_hit_records_builder_init(&l.builder))
		return (true);
	if (append_records(l.preprocessed, cone, l.builder))
	{
		t_ray_hit_records_builder_free(l.builder);
		return (true);
	}
	if (l.builder->count != 0 && l.builder->count != 2)
	{
		t_ray_hit_records_builder_free(l.builder);
		*out = (t_ray_hit_records){0, NULL};
		return (false);
	}
	l.result = t_ray_hit_records_builder_build(l.builder, out);
	t_ray_hit_records_builder_free(l.builder);
	l.i = -1;
	if (!l.result)
		while (++l.i < (*out).hit_record_count)
			(*out).hit_records[l.i].normal = t_f3_rotate(
					cone.rotation, (*out).hit_records[l.i].normal);
	return (l.result);
}
