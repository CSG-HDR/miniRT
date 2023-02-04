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

#include <stddef.h>

#include "ft_types.h"

static t_err	init(
	const t_ray_hit_records *rays,
	size_t count,
	t_ray_hit_records_builder **out_builder,
	t_ray_hit_records *out_merged
)
{
	t_ray_hit_records_builder	*builder;
	t_ray_hit_records			merged;

	if (t_ray_hit_records_builder_init(&builder))
		return (true);
	if (t_ray_merge(rays, count, &merged))
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

t_err	t_ray_union(
	const t_ray_hit_records *rays,
	size_t count,
	t_ray_hit_records *out
)
{
	t_ray_hit_records_builder	*builder;
	t_ray_hit_records			merged;
	size_t						i;
	size_t						prev_sum;
	size_t						sum;

	if (init(rays, count, &builder, &merged))
		return (true);
	sum = 0;
	i = -1;
	while (++i < merged.hit_record_count)
	{
		prev_sum = sum;
		sum += 2 * (!!merged.hit_records[i].is_front_face) - 1;
		if ((prev_sum == 0 || sum == 0)
			&& t_ray_hit_records_builder_add(builder, merged.hit_records[i]))
			return (fini_ko(builder, merged));
	}
	return (fini_ok(builder, merged, out));
}
