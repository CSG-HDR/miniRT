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
#include "wrap.h"

t_err	t_ray_hit_records_builder_init(t_ray_hit_records_builder **out)
{
	t_ray_hit_records_builder *const	result
		= wrap_malloc(sizeof(t_ray_hit_records_builder));

	if (!result)
		return (true);
	result->head = NULL;
	result->tail = NULL;
	result->count = 0;
	*out = result;
	return (false);
}
