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

int	ft_cstring_compare_length(const char *s1, const char *s2, size_t len)
{
	const unsigned char	*a;
	const unsigned char	*b;

	a = (const unsigned char *) s1;
	b = (const unsigned char *) s2;
	len++;
	while (--len && *a && *b)
	{
		if (*a != *b)
			break ;
		a++;
		b++;
	}
	if (!len)
		return (0);
	return ((int) *a - *b);
}
