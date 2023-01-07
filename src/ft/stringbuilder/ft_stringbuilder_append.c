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
#include "ft_memory.h"

static t_stringbuilder_node	*internal(
	t_stringbuilder *self,
	size_t length,
	const char *buffer
)
{
	t_stringbuilder_node	*node;
	size_t					size;

	size = length;
	if (length < self->buffer_size)
		size = self->buffer_size;
	node = wrap_malloc(sizeof(t_stringbuilder_node) + size);
	if (!node)
		return (NULL);
	node->next = NULL;
	node->capacity = size;
	ft_memory_copy(node->str, buffer, length);
	node->length = length;
	if (self->tail)
		self->tail->next = node;
	else
		self->head = node;
	self->tail = node;
	return (node);
}

t_err	stringbuilder_append(
	t_stringbuilder *self,
	size_t len,
	const char *buffer
)
{
	t_stringbuilder_node *const	tail = self->tail;
	size_t						offset;
	t_stringbuilder_node		*new_tail;

	offset = 0;
	if (self->tail)
		offset = self->tail->capacity - self->tail->length;
	if (offset >= len)
	{
		ft_memory_copy(&self->tail->str[self->tail->length], buffer, len);
		self->tail->length += len;
		self->length += len;
		return (false);
	}
	new_tail = internal(self, len - offset, &buffer[offset]);
	if (!new_tail)
		return (true);
	if (offset)
	{
		ft_memory_copy(&tail->str[tail->length], buffer, offset);
		tail->length += offset;
	}
	self->length += len;
	return (false);
}
