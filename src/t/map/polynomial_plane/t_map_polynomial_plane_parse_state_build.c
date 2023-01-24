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
#include "wrap.h"

static size_t	list_length(t_map_polynomial_plane_parse_state *state)
{
	t_map_polynomial_plane_parse_state_node	*current;
	size_t									result;

	current = state->head;
	result = 0;
	while (current)
	{
		result++;
		current = current->next;
	}
	return (result);
}

t_err	t_map_polynomial_plane_parse_state_build(
	t_map_polynomial_plane_parse_state *in,
	t_map_polynomial_plane **out
)
{
	const size_t							length = list_length(in);
	t_map_polynomial_plane *const			result
		= wrap_malloc(sizeof(t_map_polynomial_plane));
	t_map_monomial *const					monomials
		= wrap_malloc(sizeof(t_map_monomial) * length);
	t_map_polynomial_plane_parse_state_node	*current;
	size_t									i;

	if (!result || !monomials)
	{
		wrap_free(result);
		wrap_free(monomials);
		return (true);
	}
	current = in->head;
	i = 0;
	while (current)
	{
		monomials[i++] = current->monomial;
		current = current->next;
	}
	result->monomial_count = length;
	result->monomials = monomials;
	*out = result;
	return (false);
}
