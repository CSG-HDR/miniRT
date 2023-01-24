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

typedef struct s_locals
{
	bool	has_coefficient;
	bool	has_x;
	bool	has_y;
	bool	has_z;
}	t_locals;

bool	t_map_polynomial_plane_validate_monomial(const char *str)
{
	t_locals	l;

	l = (t_locals){false, false, false, false};
	l.has_coefficient = t_map_polynomial_plane_validate_has_coefficient(str);
	if (l.has_coefficient && !t_map_polynomial_plane_validate_coefficient(str))
		return (false);
	if (l.has_coefficient)
		str += t_map_polynomial_plane_validate_coefficient_size(str);
	l.has_x = t_map_polynomial_plane_validate_has_x(str);
	if (l.has_x && !t_map_polynomial_plane_validate_x(str))
		return (false);
	if (l.has_x)
		str += t_map_polynomial_plane_validate_x_size(str);
	l.has_y = t_map_polynomial_plane_validate_has_y(str);
	if (l.has_y && !t_map_polynomial_plane_validate_y(str))
		return (false);
	if (l.has_y)
		str += t_map_polynomial_plane_validate_y_size(str);
	l.has_z = t_map_polynomial_plane_validate_has_z(str);
	if (l.has_z && !t_map_polynomial_plane_validate_z(str))
		return (false);
	if (l.has_z)
		str += t_map_polynomial_plane_validate_z_size(str);
	return ((*str == '\0' || *str == '+' || *str == '-')
		&& (l.has_coefficient || l.has_x || l.has_y || l.has_z));
}
