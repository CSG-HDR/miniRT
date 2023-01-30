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

#include "t_ray.h"

#include <stdbool.h>

#include "ft_types.h"
#include "wrap.h"

static bool	remove_duplicate_record(
	t_ray_hit_records_builder *self,
	t_ray_hit_record record
)
{
	t_ray_hit_records_builder_node	*prev;
	t_ray_hit_records_builder_node	*to_remove;

	if (self->head && self->head->record.distance == record.distance
		&& self->head->record.is_front_face != record.is_front_face)
	{
		to_remove = self->head;
		self->head = to_remove->next;
		wrap_free(to_remove);
		return (true);
	}
	prev = self->head;
	while (prev && prev->next)
	{
		if (prev->next->record.distance == record.distance
			&& self->head->record.is_front_face != record.is_front_face)
		{
			to_remove = prev->next;
			prev->next = to_remove->next;
			wrap_free(prev->next);
			return (true);
		}
		prev = prev->next;
	}
	return (false);
}

t_err	t_ray_hit_records_builder_add(
	t_ray_hit_records_builder *self,
	t_ray_hit_record record
)
{
	t_ray_hit_records_builder_node	*node;

	if (remove_duplicate_record(self, record))
		return (false);
	node = wrap_malloc(sizeof(t_ray_hit_records_builder_node));
	if (!node)
		return (true);
	node->next = NULL;
	node->record = record;
	if (self->tail)
		self->tail->next = node;
	else
		self->head = node;
	self->tail = node;
	self->count++;
	return (false);
}
