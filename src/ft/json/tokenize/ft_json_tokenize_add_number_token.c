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

#include "ft_json_internal.h"

#include <stdlib.h>

static double	exponential(double n, int e)
{
	while (e < 0)
	{
		e++;
		n /= 10;
	}
	while (e > 0)
	{
		e--;
		n *= 10;
	}
	return (n);
}

t_err	ft_json_tokenize_add_number_token(
	t_ft_json_token_list *list,
	t_ft_json_tokenizer_state_number *state
)
{
	t_ft_json_token_number *const		token
		= malloc(sizeof(t_ft_json_token_number));
	t_ft_json_token_list_node *const	node
		= malloc(sizeof(t_ft_json_token_list_node));
	const double						number
		= exponential(state->value * state->sign, state->exp * state->exp_sign);

	free(state);
	if (!token || !node)
	{
		free(token);
		free(node);
		return (true);
	}
	*token = (t_ft_json_token_number){FT_JSON_TOKEN_TYPE_NUMBER, number};
	node->next = NULL;
	node->value.number = token;
	node->free_value = (void (*)(t_ft_json_token))free;
	if (list->head)
		list->tail->next = node;
	else
		list->head = node;
	list->tail = node;
	return (false);
}
