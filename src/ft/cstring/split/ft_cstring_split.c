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

#include <stdbool.h>

#include "wrap.h"
#include "ft_cstring.h"

typedef struct s_ft_cstring_split
{
	size_t		index;
	bool		alloc_failed;
	const char	*tmp;
}	t_ft_cstring_split;

char	**ft_cstring_split(const char *str, const char *charset)
{
	t_ft_cstring_split	l;
	const size_t		len = ft_cstring_split_count(str, charset);
	char **const		result
		= (char **)wrap_malloc(sizeof(char *) * (len + 1));

	l.alloc_failed = false;
	if (!result)
		return (NULL);
	result[len] = NULL;
	l.index = 0;
	str = ft_cstring_find_one_of(str, charset, true);
	while (*str)
	{
		l.tmp = ft_cstring_find_one_of(str, charset, false);
		result[l.index] = NULL;
		if (ft_cstring_duplicate_length(str, l.tmp - str, &result[l.index++]))
			l.alloc_failed = true;
		if (!*l.tmp || l.alloc_failed)
			break ;
		str = ft_cstring_find_one_of(l.tmp, charset, true);
	}
	if (!l.alloc_failed)
		return (result);
	ft_cstring_split_free(result);
	return (NULL);
}
