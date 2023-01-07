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

static bool	ft_simple_map_dynamic_pop_internal(
	t_ft_simple_map_dynamic **self,
	const void *key,
	size_t key_length,
	void **out
)
{
	bool	result;
	bool	need_cleanup;
	size_t	i;

	if (!key_length)
	{
		*out = (*self)->value;
		(*self)->value = NULL;
		result = !*out;
	}
	else
		result = (
				!(*self)->array[*((unsigned char *)key)]
				|| ft_simple_map_dynamic_pop_internal(
					&(*self)->array[*((unsigned char *)key)],
					((unsigned char *)key) + 1,
					key_length - 1,
					out));
	need_cleanup = !(*self)->value;
	i = -1;
	while (++i < (1 << CHAR_BIT) && need_cleanup)
		need_cleanup = !(*self)->array[i];
	wrap_free(*self);
	*self = NULL;
	return (result);
}

bool	ft_simple_map_dynamic_pop(
	t_ft_simple_map_dynamic *self,
	const void *key,
	size_t key_length,
	void **out
)
{
	if (!key_length)
	{
		*out = self->value;
		self->value = NULL;
		return (!*out);
	}
	if (!self->array[*((unsigned char *)key)])
		return (true);
	return (ft_simple_map_dynamic_pop_internal(
			&self->array[*((unsigned char *)key)],
			((unsigned char *)key) + 1,
			key_length - 1,
			out));
}
