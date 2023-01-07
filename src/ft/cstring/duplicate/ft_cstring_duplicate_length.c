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

t_err	ft_cstring_duplicate_length(const char *src, size_t max_len, char **out)
{
	size_t		length;
	char		*result;
	const char	*tmp;
	char		*temp;

	tmp = src;
	length = 0;
	while (*tmp++ && ++length < max_len)
		;
	result = wrap_malloc(length + 1);
	if (!result)
		return (true);
	temp = result;
	length = 0;
	while (*src && length++ < max_len)
		*temp++ = *src++;
	*temp = '\0';
	*out = result;
	return (false);
}
