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

#include "ft_memory.h"

t_err	ft_cstring_concat(const char *a, const char *b, char **out)
{
	const size_t	a_length = ft_cstring_length(a);
	const size_t	b_length = ft_cstring_length(b);
	char *const		result = wrap_malloc(a_length + b_length + 1);

	if (!result)
		return (true);
	ft_memory_copy(result, a, a_length);
	ft_memory_copy(result + a_length, b, b_length);
	result[a_length + b_length] = '\0';
	*out = result;
	return (false);
}
