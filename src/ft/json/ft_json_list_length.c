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

#include "ft_json.h"

#include <stddef.h>

#include "ft_json_internal.h"

size_t	ft_json_list_length(t_ft_json value)
{
	t_ft_json_value_internal *const	self = value;
	t_ft_json_list_node				*current;
	size_t							result;

	result = 0;
	current = self->list.value.head;
	while (current)
	{
		result++;
		current = current->next;
	}
	return (result);
}
