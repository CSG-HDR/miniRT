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

t_err	t_ray_nearest(
	t_ray_hit_records a,
	t_ray_hit_records b,
	t_ray_hit_records *out
)
{
	if (!a.hit_record_count || !b.hit_record_count)
	{
		if (!a.hit_record_count && b.hit_record_count)
		{
			*out = (t_ray_hit_records){0, NULL};
			return (false);
		}
		if (a.hit_record_count)
			return (t_ray_hit_records_copy_first(a, out));
		return (t_ray_hit_records_copy_first(b, out));
	}
	if (a.hit_records[0].distance < b.hit_records[0].distance)
		return (t_ray_hit_records_copy_first(a, out));
	return (t_ray_hit_records_copy_first(b, out));
}
