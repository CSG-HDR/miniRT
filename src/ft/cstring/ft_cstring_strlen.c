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

#include "ft_cstring.h"

#include <limits.h>

#include "ft_byte_map.h"

size_t	ft_strlen_until_set(
	const char *str,
	const char *set,
	bool include_null
)
{
	t_byte	map[1 << CHAR_BIT];

	ft_byte_map(map, include_null, (t_byte *) set);
	return (ft_strlen_until_map(str, map));
}

size_t	ft_strlen_until_map(
	const char *str,
	const t_byte *map
)
{
	size_t	result;

	result = 0;
	while (!map[*((t_byte *) str)])
	{
		str++;
		result++;
	}
	return (result);
}
