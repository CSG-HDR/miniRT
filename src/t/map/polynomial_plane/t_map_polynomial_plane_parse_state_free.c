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

void	t_map_polynomial_plane_parse_state_free(
	t_map_polynomial_plane_parse_state *state
)
{
	t_map_polynomial_plane_parse_state_node	*to_free;

	while (state->head)
	{
		to_free = state->head;
		state->head = to_free->next;
		wrap_free(to_free);
	}
	wrap_free(state);
}
