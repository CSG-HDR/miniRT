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
#include "ft_os_file.h"
#include "t_image.h"
#include "wrap.h"

static t_err	create_node(const char *path, t_texture_manager_node **out)
{
	size_t							length;
	char *const						file_contents
		= ft_os_file_read(path, &length);
	t_texture_manager_node *const	node
		= wrap_malloc(sizeof(t_texture_manager_node));

	if (!file_contents || !node
		|| t_image_deserialize(file_contents, length, &node->image))
	{
		wrap_free(file_contents);
		wrap_free(node);
		return (true);
	}
	wrap_free(file_contents);
	if (ft_cstring_duplicate(path, &node->path))
	{
		wrap_free(node->image);
		wrap_free(node);
		return (true);
	}
	node->next = NULL;
	*out = node;
	return (false);
}

t_err	t_texture_manager_preload(t_texture_manager *self, const char *path)
{
	t_texture_manager_node	*node;

	if (t_texture_manager_get(self, path))
		return (false);
	if (create_node(path, &node))
		return (true);
	if (self->tail)
		self->tail->next = node;
	else
		self->head = node;
	self->tail = node;
	return (false);
}
