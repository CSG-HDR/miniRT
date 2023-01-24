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
#include "t_map.h"

t_err	t_map_polynomial_plane_parse(
	const char *str,
	t_map_polynomial_plane **out
)
{
	t_map_polynomial_plane_parse_state	*state;
	t_err								result;

	if (t_map_polynomial_plane_parse_state_init(&state))
		return (true);
	while (*str)
	{
		if (t_map_polynomial_plane_parse_next(state, *str++))
		{
			t_map_polynomial_plane_parse_state_free(state);
			return (true);
		}
	}
	result = t_map_polynomial_plane_parse_state_build(state, out);
	t_map_polynomial_plane_parse_state_free(state);
	return (result);
}
