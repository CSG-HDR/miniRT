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

#include "ft_types.h"
#include "t_map.h"
#include "wrap.h"

static t_err	free_and_return(
	t_ray_hit_records *records,
	size_t count,
	t_err result
)
{
	while (count--)
		t_ray_hit_records_free(records[count]);
	wrap_free(records);
	return (result);
}

t_err	t_ray_constructive_union(
	t_ray ray,
	t_map_union _union,
	t_ray_hit_records *out
)
{
	t_ray_hit_records *const	each
		= wrap_malloc(sizeof(t_ray_hit_records) * _union.children_count);
	size_t						i;

	if (!each)
		return (true);
	i = -1;
	while (++i < _union.children_count)
		if (t_ray_model(ray, _union.children[i], &each[i]))
			return (free_and_return(each, i, true));
	if (t_ray_union(each, _union.children_count, out))
		return (free_and_return(each, _union.children_count, true));
	return (free_and_return(each, _union.children_count, false));
}
