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
#include "ft_memory.h"

t_err	t_ray_hit_records_copy_first(
	t_ray_hit_records src,
	t_ray_hit_records *dest
)
{
	t_ray_hit_record *const	node
		= ft_memory_duplicate(src.hit_records, sizeof(t_ray_hit_record));

	if (!node)
		return (true);
	*dest = (t_ray_hit_records){1, node};
	return (false);
}
