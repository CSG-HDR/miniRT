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

#ifdef DEVELOPMENT

# include "ft_debug.h"

size_t	ft_cstring_find_index_reverse(const char *str, char ch)
{
	size_t	result;
	size_t	i;

	if (!str)
		ft_debug_die(
			"ft_cstring_find_index_reverse(): wrong parameter given\n");
	i = -1;
	result = -1;
	while (str[++i])
		if (str[i] == ch)
			result = i;
	return (result);
}

#else

size_t	ft_cstring_find_index_reverse(const char *str, char ch)
{
	size_t	result;
	size_t	i;

	i = -1;
	result = -1;
	while (str[++i])
		if (str[i] == ch)
			result = i;
	return (result);
}

#endif
