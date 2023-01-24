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

#include <stdbool.h>

bool	t_map_polynomial_plane_validate(const char *str)
{
	int	state;

	state = T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_START;
	while (state != T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_ERROR && *str)
		state = t_map_polynomial_plane_validate_next(state, *str++);
	if (state == T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_ERROR)
		return (false);
	return (
		t_map_polynomial_plane_validate_next(state, '\n')
		== T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_END
	);
}
