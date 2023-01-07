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

static void	ft_simple_map_static_pop_internal_cleanup(
	t_ft_simple_map_static_value **current
)
{
	size_t	i;

	i = 0;
	while (i < (1 << CHAR_BIT))
		if ((*current)->value[i++])
			return ;
	wrap_free(*current);
	*current = NULL;
}

static bool	ft_simple_map_static_pop_internal(
	const t_ft_simple_map_static_context_get *context,
	t_ft_simple_map_static_value **current,
	size_t depth
)
{
	const size_t	index = ((unsigned char *) context->key)[depth];
	bool			error;

	if (!*current)
		return (true);
	if (depth + 1 == context->self->key_length)
	{
		if (context->out)
			*context->out = (*current)->value[index];
		(*current)->value[index] = NULL;
		error = false;
	}
	else
		error = ft_simple_map_static_pop_internal(
				context,
				&(*current)->array[index],
				depth + 1);
	ft_simple_map_static_pop_internal_cleanup(current);
	return (error);
}

bool	ft_simple_map_static_pop(
	t_ft_simple_map_static *self,
	const void *key,
	void **out
)
{
	const t_ft_simple_map_static_context_get	context = {self, key, out};

	return (
		ft_simple_map_static_pop_internal(
			&context,
			&self->values,
			0
		)
	);
}
