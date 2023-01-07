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

#include "ft_stringbuilder.h"

#include "wrap.h"

void	stringbuilder_free(t_stringbuilder *self)
{
	t_stringbuilder_node	*current;
	t_stringbuilder_node	*next;

	current = self->head;
	while (current)
	{
		next = current->next;
		wrap_free(current);
		current = next;
	}
	wrap_free(self);
}
