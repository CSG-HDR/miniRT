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

static bool	ft_simple_map_static_get_internal(
	const t_ft_simple_map_static_context_get *context,
	t_ft_simple_map_static_value **current,
	size_t depth
)
{
	const size_t	index = ((unsigned char *) context->key)[depth];

	if (!*current)
		return (true);
	if (depth + 1 == context->self->key_length)
	{
		if (!(*current)->value[index])
			return (true);
		if (context->out)
			*context->out = (*current)->value[index];
		return (false);
	}
	return (
		ft_simple_map_static_get_internal(
			context,
			&(*current)->array[index],
			depth + 1
		)
	);
}

bool	ft_simple_map_static_get(
	t_ft_simple_map_static *self,
	const void *key,
	void **out
)
{
	const t_ft_simple_map_static_context_get	context = {self, key, out};

	return (
		ft_simple_map_static_get_internal(
			&context,
			&self->values,
			0
		)
	);
}
