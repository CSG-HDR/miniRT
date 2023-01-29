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

#include "ft_types.h"
#include "wrap.h"

t_err	t_ray_hit_records_builder_add(
	t_ray_hit_records_builder *self,
	t_ray_hit_record record
)
{
	t_ray_hit_records_builder_node *const	node
		= wrap_malloc(sizeof(t_ray_hit_records_builder_node));

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
