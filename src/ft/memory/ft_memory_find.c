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

#include "ft_memory.h"

bool	ft_memory_find(const void *mem, size_t size, char to_find, size_t *out)
{
	const char *const	mem_c = (char *)mem;
	size_t				i;

	i = 0;
	while (i < size)
	{
		if (mem_c[i] == to_find)
		{
			if (out)
				*out = i;
			return (true);
		}
		i++;
	}
	return (false);
}
