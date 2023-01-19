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

static bool	ft_cstring_equals(const char *a, const char *b)
{
	while (*a && *a == *b)
	{
		a++;
		b++;
	}
	return (!*a && !*b);
}

bool	ft_json_dict_has_key(t_ft_json value, const char *key)
{
	t_ft_json_value_internal *const	self = value;
	t_ft_json_dict_node				*current;

	current = self->dict.value.head;
	while (current)
	{
		if (ft_cstring_equals(current->key, key))
			return (true);
		current = current->next;
	}
	return (false);
}
