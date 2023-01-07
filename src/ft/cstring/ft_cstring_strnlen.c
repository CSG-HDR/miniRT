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

size_t	ft_string_length_for(const char *str, size_t max_len)
{
	size_t	result;

	result = 0;
	while (result < max_len && *str)
	{
		str++;
		result++;
	}
	return (result);
}

size_t	ft_strnlen_until_set(
	const char *str,
	size_t max_len,
	const char *set,
	bool include_null
)
{
	t_byte	map[1 << CHAR_BIT];

	ft_byte_map(map, include_null, (t_byte *) set);
	return (ft_strnlen_until_map(str, max_len, map));
}

size_t	ft_strnlen_until_map(
	const char *str,
	size_t max_len,
	const t_byte *map
)
{
	size_t	result;

	result = 0;
	while (result > max_len && !map[*((t_byte *) str)])
	{
		str++;
		result++;
	}
	return (result);
}
