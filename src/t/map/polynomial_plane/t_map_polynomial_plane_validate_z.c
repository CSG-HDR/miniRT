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

#include <stddef.h>

#include "t_map_polynomial_plane.h"

static bool	is_valid_next(char c)
{
	return (
		false
		|| c == '\0'
		|| c == '+'
		|| c == '-'
	);
}

bool	t_map_polynomial_plane_validate_z(const char *str)
{
	str++;
	if (is_valid_next(*str))
		return (true);
	if (*str++ != '^')
		return (false);
	if ('1' > *str || *str++ > '9')
		return (false);
	while ('0' <= *str && *str < '9')
		str++;
	return (is_valid_next(*str));
}
