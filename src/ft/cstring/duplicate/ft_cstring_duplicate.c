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

#include "wrap.h"

t_err	ft_cstring_duplicate(const char *src, char **out)
{
	const size_t	length = ft_cstring_length(src);
	char *const		result = wrap_malloc(length + 1);
	const char		*tmp;
	char			*temp;

	if (!result)
		return (true);
	tmp = src;
	temp = result;
	while (*src)
		*temp++ = *tmp++;
	*temp = '\0';
	*out = result;
	return (false);
}
