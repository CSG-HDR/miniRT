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

#include "ft_stringbuilder.h"

typedef t_ft_json_token_string		t_token;
typedef t_ft_json_token_list_node	t_node;

static void	free_value(t_ft_json_token value)
{
	free(value.string->value);
	free(value.string);
}

t_err	ft_json_tokenize_add_string_token(
	t_ft_json_token_list *list,
	t_ft_json_tokenizer_state_string *state
)
{
	char *const		string = stringbuilder_to_string(state->stringbuilder, 0);
	t_token *const	token = malloc(sizeof(t_token));
	t_node *const	node = malloc(sizeof(t_node));

	stringbuilder_free(state->stringbuilder);
	free(state);
	if (!string || !token || !node)
	{
		free(string);
		free(token);
		free(node);
		return (true);
	}
	*token = (t_token){FT_JSON_TOKEN_TYPE_STRING, string};
	node->next = NULL;
	node->free_value = free_value;
	node->value.string = token;
	if (list->head)
		list->tail->next = node;
	else
		list->head = node;
	list->tail = node;
	return (false);
}
