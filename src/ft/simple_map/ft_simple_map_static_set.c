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
#include "ft_memory.h"

static t_err	ft_simple_map_static_set_internal(
	const t_ft_simple_map_static_context_set *context,
	t_ft_simple_map_static_value **current,
	size_t depth
)
{
	const size_t	index = ((unsigned char *) context->key)[depth];
	const bool		fresh = !*current;
	t_err			error;

	if (fresh)
		*current = (t_ft_simple_map_static_value *)
			ft_memory_allocate(1, sizeof(t_ft_simple_map_static_value));
	if (!*current)
		return (true);
	if (depth + 1 == context->self->key_length)
	{
		if ((*current)->value[index])
			return (true);
		(*current)->value[index] = context->value;
		return (false);
	}
	error = ft_simple_map_static_set_internal(
			context,
			&(*current)->array[index],
			depth + 1);
	if (!(error && fresh))
		return (error);
	wrap_free(*current);
	*current = NULL;
	return (error);
}

t_err	ft_simple_map_static_set(
	t_ft_simple_map_static *self,
	const void *key,
	void *value
)
{
	const t_ft_simple_map_static_context_set	context = {self, key, value};

	return (
		ft_simple_map_static_set_internal(
			&context,
			&self->values,
			0
		)
	);
}
