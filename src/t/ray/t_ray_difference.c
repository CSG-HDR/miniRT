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

#include "t_ray.h"

#include <stdbool.h>
#include <stddef.h>

#include "ft_types.h"
#include "t_f3.h"
#include "t_map.h"

static t_err	init(
	t_ray_hit_records from,
	t_ray_hit_records subtract,
	t_ray_hit_records_builder **out_builder,
	t_ray_hit_records *out_merged
)
{
	const t_ray_hit_records		rays[3] = {from, from, subtract};
	t_ray_hit_records_builder	*builder;
	t_ray_hit_records			merged;

	if (t_ray_hit_records_builder_init(&builder))
		return (true);
	if (t_ray_merge(rays, 3, &merged))
	{
		t_ray_hit_records_builder_free(builder);
		return (true);
	}
	*out_builder = builder;
	*out_merged = merged;
	return (false);
}

static t_err	fini_ok(
	t_ray_hit_records_builder *builder,
	t_ray_hit_records merged,
	t_ray_hit_records *out
)
{
	t_err	result;

	result = t_ray_hit_records_builder_build(builder, out);
	t_ray_hit_records_builder_free(builder);
	t_ray_hit_records_free(merged);
	return (result);
}

static t_err	fini_ko(
	t_ray_hit_records_builder *builder,
	t_ray_hit_records merged
)
{
	t_ray_hit_records_builder_free(builder);
	t_ray_hit_records_free(merged);
	return (true);
}

typedef struct s_locals
{
	t_ray_hit_records_builder	*builder;
	t_ray_hit_records			merged;
	size_t						i;
	size_t						prev_sum;
	size_t						sum;
	bool						is_front_face;
}	t_locals;

static t_ray_hit_record	enhance(t_ray_hit_record record, t_locals *l)
{
	t_map_normal	normal;

	normal = record.normal;
	l->is_front_face = !l->is_front_face;
	if (l->is_front_face != record.is_front_face)
		normal = t_f3_neg(normal);
	return ((t_ray_hit_record){
		record.distance,
		normal,
		record.material,
		l->is_front_face,
		record.x,
		record.y
	});
}

t_err	t_ray_difference(
	t_ray_hit_records from,
	t_ray_hit_records subtract,
	t_ray_hit_records *out
)
{
	t_locals	l;

	l.is_front_face = false;
	if (init(from, subtract, &l.builder, &l.merged))
		return (true);
	l.sum = 0;
	l.i = -1;
	while (++l.i < l.merged.hit_record_count)
	{
		l.prev_sum = l.sum;
		l.sum += 2 * (!!l.merged.hit_records[l.i].is_front_face) - 1;
		if (l.prev_sum == 2 || l.sum == 2)
		{
			if (t_ray_hit_records_builder_add(
					l.builder, enhance(l.merged.hit_records[l.i], &l)))
			return (fini_ko(l.builder, l.merged));
		}
	}
	return (fini_ok(l.builder, l.merged, out));
}
