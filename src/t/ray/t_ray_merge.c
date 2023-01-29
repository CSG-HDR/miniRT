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

t_err	t_ray_merge(
	t_ray_hit_records *rays,
	size_t count,
	t_ray_hit_records *out
)
{
	t_ray_hit_records_builder	*builder;
	size_t						i;
	size_t						j;
	t_err						result;

	if (t_ray_hit_records_builder_init(&builder))
		return (true);
	i = -1;
	while (++i < count)
	{
		j = -1;
		while (++j < rays[i].hit_record_count)
		{
			if (t_ray_hit_records_builder_add(builder, rays[i].hit_records[j]))
			{
				t_ray_hit_records_builder_free(builder);
				return (true);
			}
		}
	}
	result = t_ray_hit_records_builder_build(builder, out);
	t_ray_hit_records_builder_free(builder);
	return (result);
}
