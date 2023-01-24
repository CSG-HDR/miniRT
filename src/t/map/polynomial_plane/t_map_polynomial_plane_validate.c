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

#include "t_map_polynomial_plane.h"

bool	t_map_polynomial_plane_validate(const char *str)
{
	if (*str == '-')
		str++;
	if (!t_map_polynomial_plane_validate_monomial(str))
		return (false);
	str += t_map_polynomial_plane_validate_next_monomial_offset(str);
	while (*str)
	{
		str++;
		if (!t_map_polynomial_plane_validate_monomial(str))
			return (false);
		str += t_map_polynomial_plane_validate_next_monomial_offset(str);
	}
	return (true);
}
