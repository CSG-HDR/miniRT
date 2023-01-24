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

#include "wrap.h"
#include "ft_types.h"

t_err	t_map_polynomial_plane_parse_state_init(
	t_map_polynomial_plane_parse_state **out
)
{
	t_map_polynomial_plane_parse_state *const	result
		= wrap_malloc(sizeof(t_map_polynomial_plane_parse_state));

	if (!result)
		return (true);
	result->current_dight = 1.0;
	result->is_coefficient_minus = false;
	result->current.coefficient = 1;
	result->current.degree_of_x = 0;
	result->current.degree_of_y = 0;
	result->current.degree_of_z = 0;
	result->head = NULL;
	result->tail = NULL;
	*out = result;
	return (false);
}
