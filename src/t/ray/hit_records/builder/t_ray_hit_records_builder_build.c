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

static void	sort(t_ray_hit_records mut)
{
	t_ray_hit_record	tmp;
	size_t				i;
	size_t				j;

	i = mut.hit_record_count;
	while (i--)
	{
		j = i;
		while (j--)
		{
			if (mut.hit_records[i].distance < mut.hit_records[j].distance)
			{
				tmp = mut.hit_records[i];
				mut.hit_records[i] = mut.hit_records[j];
				mut.hit_records[j] = tmp;
			}
		}
	}
}

t_err	t_ray_hit_records_builder_build(
	t_ray_hit_records_builder *self,
	t_ray_hit_records *out
)
{
	t_ray_hit_record *const			nodes
		= wrap_malloc(sizeof(t_ray_hit_record) * self->count);
	t_ray_hit_records				result;
	size_t							i;
	t_ray_hit_records_builder_node	*current;

	if (!nodes)
	{
		wrap_free(nodes);
		return (true);
	}
	i = 0;
	current = self->head;
	while (current)
	{
		nodes[i++] = current->record;
		current = current->next;
	}
	result.hit_record_count = self->count;
	result.hit_records = nodes;
	sort(result);
	*out = result;
	return (false);
}
