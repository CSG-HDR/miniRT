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

#include <stdbool.h>

#include "t_map_polynomial_plane.h"

static bool	is_valid_next(char c)
{
	return (
		false
		|| c == '\0'
		|| c == '+'
		|| c == '-'
		|| c == 'x'
		|| c == 'y'
		|| c == 'z'
	);
}

bool	t_map_polynomial_plane_validate_coefficient(const char *str)
{
	bool	ends_with_zero;

	if (*str == '0')
	{
		if (*++str != '.')
			return (false);
		ends_with_zero = true;
		while ('0' <= *++str && *str <= '9')
			ends_with_zero = (*str == '0');
		return (!ends_with_zero && is_valid_next(*str));
	}
	while ('0' <= *str && *str <= '9')
		str++;
	ends_with_zero = false;
	if (*str == '.')
	{
		ends_with_zero = true;
		while ('0' <= *++str && *str <= '9')
			ends_with_zero = (*str == '0');
	}
	return (!ends_with_zero && is_valid_next(*str));
}
