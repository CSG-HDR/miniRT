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

# include <stdlib.h>
# include <unistd.h>

# include "ft_io.h"
# include "ft_exit.h"

size_t	ft_cstring_find_index_reverse(const char *str, char ch)
{
	size_t	result;
	size_t	i;

	if (!str)
	{
		ft_puts(
			STDERR_FILENO,
			"ft_cstring_find_index_reverse(): wrong parameter given\n");
		ft_exit(EXIT_FAILURE);
		return (0);
	}
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
