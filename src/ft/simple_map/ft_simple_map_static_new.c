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

#include "ft_simple_map_internal.h"
#include "ft_simple_map.h"

#include "wrap.h"

t_ft_simple_map_static	*new_ft_simple_map_static(size_t key_length)
{
	t_ft_simple_map_static	*result;

	if (!key_length)
		return (NULL);
	result
		= (t_ft_simple_map_static *)wrap_malloc(sizeof(t_ft_simple_map_static));
	if (!result)
		return (NULL);
	result->key_length = key_length;
	result->values = NULL;
	return (result);
}
