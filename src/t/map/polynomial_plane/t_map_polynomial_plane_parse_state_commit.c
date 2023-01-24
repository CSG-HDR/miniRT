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

#include "t_map.h"
#include "t_map_polynomial_plane.h"

#include <stdbool.h>

#include "ft_types.h"
#include "wrap.h"

static bool	has_same_degree(t_map_monomial a, t_map_monomial b)
{
	return (
		true
		&& a.degree_of_x == b.degree_of_x
		&& a.degree_of_y == b.degree_of_y
		&& a.degree_of_z == b.degree_of_z
	);
}

static t_map_polynomial_plane_parse_state_node	*find_same_degree_node(
	t_map_polynomial_plane_parse_state *state
)
{
	t_map_polynomial_plane_parse_state_node	*current;

	current = state->head;
	while (current)
	{
		if (has_same_degree(current->monomial, state->current))
			return (current);
		current = current->next;
	}
	return (NULL);
}

t_err	t_map_polynomial_plane_parse_state_commit(
	t_map_polynomial_plane_parse_state *state
)
{
	t_map_polynomial_plane_parse_state_node	*node;

	node = find_same_degree_node(state);
	if (node)
		node->monomial.coefficient += state->current.coefficient;
	else
	{
		node = wrap_malloc(sizeof(t_map_polynomial_plane_parse_state_node));
		if (!node)
			return (true);
		node->monomial = state->current;
		node->next = NULL;
		if (state->tail)
			state->tail->next = node;
		else
			state->head = node;
		state->tail = node;
	}
	state->current.coefficient = 0;
	state->current.degree_of_x = 0;
	state->current.degree_of_y = 0;
	state->current.degree_of_z = 0;
	return (false);
}
