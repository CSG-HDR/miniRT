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

typedef t_err					(*t_state_function)(
									t_map_polynomial_plane_parse_state *state,
									char c
								);

static const t_state_function	g_state_functions[] = {
	t_map_polynomial_plane_parse_start,
	t_map_polynomial_plane_parse_first_minus,
	t_map_polynomial_plane_parse_first_coefficient_digit_first,
	t_map_polynomial_plane_parse_first_coefficient_digit_repeat,
	t_map_polynomial_plane_parse_first_coefficient_dot,
	t_map_polynomial_plane_parse_first_coefficient_decimal,
	t_map_polynomial_plane_parse_first_x,
	t_map_polynomial_plane_parse_first_x_degree,
	t_map_polynomial_plane_parse_first_x_degree_digit_first,
	t_map_polynomial_plane_parse_first_x_degree_digit_repeat,
	t_map_polynomial_plane_parse_first_y,
	t_map_polynomial_plane_parse_first_y_degree,
	t_map_polynomial_plane_parse_first_y_degree_digit_first,
	t_map_polynomial_plane_parse_first_y_degree_digit_repeat,
	t_map_polynomial_plane_parse_first_z,
	t_map_polynomial_plane_parse_first_z_degree,
	t_map_polynomial_plane_parse_first_z_degree_digit_first,
	t_map_polynomial_plane_parse_first_z_degree_digit_repeat,
	t_map_polynomial_plane_parse_repeat_plus,
	t_map_polynomial_plane_parse_repeat_minus,
	t_map_polynomial_plane_parse_repeat_coefficient_digit_first,
	t_map_polynomial_plane_parse_repeat_coefficient_digit_repeat,
	t_map_polynomial_plane_parse_repeat_coefficient_dot,
	t_map_polynomial_plane_parse_repeat_coefficient_decimal,
	t_map_polynomial_plane_parse_repeat_x,
	t_map_polynomial_plane_parse_repeat_x_degree,
	t_map_polynomial_plane_parse_repeat_x_degree_digit_first,
	t_map_polynomial_plane_parse_repeat_x_degree_digit_repeat,
	t_map_polynomial_plane_parse_repeat_y,
	t_map_polynomial_plane_parse_repeat_y_degree,
	t_map_polynomial_plane_parse_repeat_y_degree_digit_first,
	t_map_polynomial_plane_parse_repeat_y_degree_digit_repeat,
	t_map_polynomial_plane_parse_repeat_z,
	t_map_polynomial_plane_parse_repeat_z_degree,
	t_map_polynomial_plane_parse_repeat_z_degree_digit_first,
	t_map_polynomial_plane_parse_repeat_z_degree_digit_repeat,
};

t_err	t_map_polynomial_plane_parse_next(
	t_map_polynomial_plane_parse_state *state,
	char c
)
{
	return (g_state_functions[state->state](state, c));
}
