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

bool	ft_cstring_starts_with(
	const char *self,
	const char *substring,
	size_t *substring_length
)
{
	size_t	length;

	length = 0;
	while (*self && *substring && *self == *substring)
	{
		length++;
		self++;
		substring++;
	}
	if (substring_length)
		*substring_length = length;
	return (*substring == '\0');
}
