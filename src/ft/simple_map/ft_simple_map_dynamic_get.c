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

#include "ft_simple_map_internal.h"
#include "ft_simple_map.h"

bool	ft_simple_map_dynamic_get(
	t_ft_simple_map_dynamic *self,
	const void *key,
	size_t key_length,
	void **out
)
{
	if (!key_length)
	{
		*out = self->value;
		return (!*out);
	}
	if (!self->array[*((unsigned char *)key)])
		return (true);
	return (
		ft_simple_map_dynamic_get(
			self->array[*((unsigned char *)key)],
			((unsigned char *)key) + 1,
			key_length - 1,
			out
		)
	);
}
