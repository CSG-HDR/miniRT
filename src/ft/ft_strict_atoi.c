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

#include "ft_strict_atoi.h"

#include <limits.h>

t_err	ft_strict_atoi(const char *str, int *out)
{
	int	sgn;
	int	result;

	if (!str[0]
		|| (str[0] == '-' && !str[1])
		|| (str[0] == '-' && str[1] == '0')
		|| (str[0] == '0' && str[1]))
		return (true);
	result = 0;
	sgn = 1;
	if (*str == '-' && *str++)
		sgn = -1;
	while (*str)
	{
		if (!('0' <= *str && *str <= '9')
			|| result > INT_MAX / 10 || result < INT_MIN / 10
			|| (result == INT_MAX / 10
				&& (*str - '0') > (INT_MAX % 10))
			|| (result == INT_MIN / 10
				&& (*str - '0') > -(INT_MIN % 10)))
			return (true);
		result = result * 10 + (*str++ - '0') * sgn;
	}
	*out = result;
	return (false);
}
