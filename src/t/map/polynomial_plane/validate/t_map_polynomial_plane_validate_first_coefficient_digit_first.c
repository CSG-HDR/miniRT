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

int	t_map_polynomial_plane_validate_first_coefficient_digit_first(char c)
{
	if ('0' <= c && c <= '9')
		return (
			T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_FIRST_COEFFICIENT_DIGIT_REPEAT);
	if (c == '.')
		return (
			T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_FIRST_COEFFICIENT_DOT);
	if (c == 'x')
		return (
			T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_FIRST_X);
	if (c == 'y')
		return (
			T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_FIRST_Y);
	if (c == 'z')
		return (
			T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_FIRST_Z);
	if (c == '+')
		return (
			T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_REPEAT_PLUS);
	if (c == '-')
		return (
			T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_REPEAT_MINUS);
	if (c == '\0')
		return (T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_END);
	else
		return (T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_ERROR);
}
