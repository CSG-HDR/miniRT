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

#include "ft_cstring_split.h"

#include "ft_cstring.h"

size_t	ft_cstring_split_count(const char *str, const char *charset)
{
	size_t	length;

	length = 0;
	str = ft_cstring_find_one_of(str, charset, true);
	while (*str)
	{
		length++;
		str = ft_cstring_find_one_of(str, charset, false);
		if (!*str)
			break ;
		str = ft_cstring_find_one_of(str, charset, true);
	}
	return (length);
}
