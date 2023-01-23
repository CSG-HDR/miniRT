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

#include "ft_cstring.h"
#include "t_image.h"

const t_image	*t_texture_manager_get(
	t_texture_manager *self,
	const char *path
)
{
	t_texture_manager_node	*current;

	current = self->head;
	while (current)
	{
		if (ft_cstring_equals(current->path, path))
			return (current->image);
		current = current->next;
	}
	return (NULL);
}
