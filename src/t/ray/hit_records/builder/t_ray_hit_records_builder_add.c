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
#include "t_f.h"
#include "wrap.h"

static void	remove_record_head(t_ray_hit_records_builder *self)
{
	t_ray_hit_records_builder_node	*to_remove;

	to_remove = self->head;
	self->head = to_remove->next;
	if (!self->head)
		self->tail = NULL;
	wrap_free(to_remove);
	self->count--;
}

static void	remove_record_non_head(
	t_ray_hit_records_builder *self,
	t_ray_hit_records_builder_node *prev
)
{
	t_ray_hit_records_builder_node	*to_remove;

	to_remove = prev->next;
	prev->next = to_remove->next;
	if (!prev->next)
		self->tail = prev;
	wrap_free(to_remove);
	self->count--;
}

static bool	remove_duplicate_record(
	t_ray_hit_records_builder *self,
	t_ray_hit_record record
)
{
	t_ray_hit_records_builder_node	*prev;

	if (self->head && self->head->record.is_front_face != record.is_front_face
		&& t_f_abs(self->head->record.distance - record.distance) < T_F_EPSILON)
	{
		remove_record_head(self);
		return (true);
	}
	prev = self->head;
	while (prev && prev->next)
	{
		if (prev->next->record.distance == record.distance
			&& prev->next->record.is_front_face != record.is_front_face)
		{
			remove_record_non_head(self, prev);
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
