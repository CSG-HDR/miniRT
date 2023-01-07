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

const char	*ft_cstring_find_one_of(
	const char *str,
	const char *charset,
	bool negate
)
{
	const char	*tmp;

	str--;
	while (*++str)
	{
		tmp = charset - 1;
		if (negate)
		{
			while (*++tmp)
				if (*tmp == *str)
					break ;
			if (!*tmp)
				return (str);
		}
		else
		{
			while (*++tmp)
				if (*tmp == *str)
					return (str);
		}
	}
	return (str);
}
