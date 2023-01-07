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

static void	ft_simple_map_static_free_internal(
	t_ft_simple_map_static_value *current,
	void (*free_value)(void *value),
	size_t remain_depth
)
{
	size_t	i;

	if (!current)
		return ;
	i = 0;
	if (!remain_depth)
	{
		while (i < (1 << CHAR_BIT))
		{
			if (current->value[i])
				free_value(current->value[i]);
			i++;
		}
	}
	else
		while (i < (1 << CHAR_BIT))
			ft_simple_map_static_free_internal(
				current->array[i++],
				free_value,
				remain_depth - 1
				);
	wrap_free(current);
}

void	ft_simple_map_static_free(
	t_ft_simple_map_static *self,
	void (*free_value)(void *value)
)
{
	ft_simple_map_static_free_internal(
		self->values,
		free_value,
		self->key_length - 1
		);
	wrap_free(self);
}
