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

void	ft_simple_map_dynamic_free(
	t_ft_simple_map_dynamic *self,
	void (*free_value)(void *value)
)
{
	size_t	i;

	if (self->value)
		free_value(self->value);
	i = 0;
	while (i < (1 << CHAR_BIT))
	{
		if (self->array[i])
			ft_simple_map_dynamic_free(self->array[i], free_value);
		i++;
	}
	wrap_free(self);
}
