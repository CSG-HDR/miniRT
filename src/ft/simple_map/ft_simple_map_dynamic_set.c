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

#include "wrap.h"

t_err	ft_simple_map_dynamic_set(
	t_ft_simple_map_dynamic *self,
	const void *key,
	size_t key_length,
	void *value
)
{
	bool	fresh;
	t_err	result;

	if (!key_length && self->value)
		return (true);
	if (!key_length)
		self->value = value;
	if (!key_length)
		return (false);
	fresh = !self->array[*((unsigned char *)key)];
	if (fresh)
		self->array[*((unsigned char *)key)] = new_ft_simple_map_dynamic();
	if (!self->array[*((unsigned char *)key)])
		return (true);
	result = ft_simple_map_dynamic_set(
			self->array[*((unsigned char *)key)],
			((unsigned char *)key) + 1,
			key_length - 1,
			value);
	if (fresh && result)
	{
		wrap_free(self->array[*((unsigned char *)key)]);
		self->array[*((unsigned char *)key)] = NULL;
	}
	return (result);
}
