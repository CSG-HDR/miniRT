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

size_t	ft_cstring_find_index(const char *str, char ch)
{
	size_t	result;

	if (!str)
		ft_debug_die("ft_cstring_find_index(): wrong parameter given\n");
	result = -1;
	while (str[++result])
		if (str[result] == ch)
			break ;
	return (result);
}

#else

size_t	ft_cstring_find_index(const char *str, char ch)
{
	size_t	result;

	result = -1;
	while (str[++result])
		if (str[result] == ch)
			break ;
	return (result);
}

#endif
