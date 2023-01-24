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

#include "ft_types.h"

t_err	t_map_polynomial_plane_parse_first_coefficient_digit_first(
	t_map_polynomial_plane_parse_state *state,
	char c
)
{
	if ('0' <= c && c <= '9')
	{
		state->state
			= T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_FIRST_COEFFICIENT_DIGIT_REPEAT;
		state->current.coefficient = state->current.coefficient * 10 + c - '0';
	}
	else if (c == '.')
		state->state
			= T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_FIRST_COEFFICIENT_DOT;
	else if (c == 'x')
		state->state
			= T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_FIRST_X;
	else if (c == 'y')
		state->state
			= T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_FIRST_Y;
	else if (c == 'z')
		state->state
			= T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_FIRST_Z;
	else if (c == '+')
	{
		state->state = T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_REPEAT_PLUS;
	}
	else if (c == '-')
	{
		state->state = T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_REPEAT_MINUS;
	}
	else
		return (t_map_polynomial_plane_parse_state_commit(state));
}
