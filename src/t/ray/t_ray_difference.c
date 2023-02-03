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

#include "t_f.h"
#include "t_ray.h"

#include "ft_types.h"

#define INFINITY 4294967295

t_err	t_ray_difference(
	t_ray_hit_records from,
	t_ray_hit_records subtract,
	t_ray_hit_records *out
)
{
	t_ray_hit_records_builder	*builder;
	size_t						i;
	t_err						result;
	t_f							min_subtract;
	t_f							max_subtract;

	if (subtract.hit_record_count == 0)
	{
		min_subtract = INFINITY;
		max_subtract = 0;
	}
	else
	{
		min_subtract = subtract.hit_records[0].distance;
		max_subtract = subtract.hit_records[subtract.hit_record_count - 1].distance;
	}
	i = 0;
	if (t_ray_hit_records_builder_init(&builder))
		return (true);
	while (i < from.hit_record_count)
	{
		if (from.hit_records[i].distance > min_subtract && from.hit_records[i].distance < max_subtract)
		{
			++i;
			continue;
		}
		if (from.hit_records[i].distance <= min_subtract)
		{
			if (t_ray_hit_records_builder_add(builder, from.hit_records[i]))
			{
				t_ray_hit_records_builder_free(builder);
				return (true);
			}
		}
		if (subtract.hit_record_count > 0 && from.hit_records[i].distance >= max_subtract)
		{
			if (t_ray_hit_records_builder_add(builder, subtract.hit_records[subtract.hit_record_count - 1]))
			{
				t_ray_hit_records_builder_free(builder);
				return (true);
			}
		}
		++i;
	}
	result = t_ray_hit_records_builder_build(builder, out);
	t_ray_hit_records_builder_free(builder);
	return (result);
}
