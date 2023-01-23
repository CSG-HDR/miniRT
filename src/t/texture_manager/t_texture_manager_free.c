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

#include "t_texture_manager.h"

#include "wrap.h"

void	t_texture_manager_free(t_texture_manager *self)
{
	t_texture_manager_node	*to_free;

	while (self->head)
	{
		to_free = self->head;
		self->head = to_free->next;
		wrap_free(to_free->path);
		wrap_free(to_free->image);
		wrap_free(to_free);
	}
	wrap_free(self);
}
