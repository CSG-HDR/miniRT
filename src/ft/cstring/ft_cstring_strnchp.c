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

size_t	ft_strnchp(const char *str, size_t max_len, char ch)
{
	size_t	result;

	if (!str)
	{
		ft_puts(STDERR_FILENO, "ft_strnchp(): wrong parameter given\n");
		ft_exit(EXIT_FAILURE);
		return (0);
	}
	result = -1;
	while (++result < max_len && str[result])
		if (str[result] == ch)
			break ;
	return (result);
}

size_t	ft_strnrchp(const char *str, size_t max_len, char ch)
{
	size_t	result;
	size_t	i;

	if (!str)
	{
		ft_puts(STDERR_FILENO, "ft_strnrchp(): wrong parameter given\n");
		ft_exit(EXIT_FAILURE);
		return (0);
	}
	i = -1;
	result = -1;
	while (++i < max_len && str[i])
		if (str[i] == ch)
			result = i;
	return (result);
}

#else

size_t	ft_strnchp(const char *str, size_t max_len, char ch)
{
	size_t	result;

	result = -1;
	while (++result < max_len && str[result])
		if (str[result] == ch)
			break ;
	return (result);
}

size_t	ft_strnrchp(const char *str, size_t max_len, char ch)
{
	size_t	result;
	size_t	i;

	i = -1;
	result = -1;
	while (++i < max_len && str[i])
		if (str[i] == ch)
			result = i;
	return (result);
}

#endif
