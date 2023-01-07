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

typedef t_ft_json_tokenizer_state	t_s;

static t_err	special_token(
	char c,
	t_ft_json_token_list *list,
	t_ft_json_tokenizer_state *out_next_state
)
{
	*out_next_state = (t_s){FT_JSON_TOKENIZER_STATE_DEFAULT, NULL};
	return (
		(!c && ft_json_tokenize_add_simple_token(
				list, FT_JSON_TOKEN_TYPE_EOF))
		|| (c == '[' && ft_json_tokenize_add_simple_token(
				list, FT_JSON_TOKEN_TYPE_BRACKET_OPEN))
		|| (c == ']' && ft_json_tokenize_add_simple_token(
				list, FT_JSON_TOKEN_TYPE_BRACKET_CLOSE))
		|| (c == '{' && ft_json_tokenize_add_simple_token(
				list, FT_JSON_TOKEN_TYPE_BRACE_OPEN))
		|| (c == '}' && ft_json_tokenize_add_simple_token(
				list, FT_JSON_TOKEN_TYPE_BRACE_CLOSE))
		|| (c == ':' && ft_json_tokenize_add_simple_token(
				list, FT_JSON_TOKEN_TYPE_COLON))
		|| (c == ',' && ft_json_tokenize_add_simple_token(
				list, FT_JSON_TOKEN_TYPE_COMMA))
	);
}

static t_err	transition_to_number(
	char c,
	t_ft_json_tokenizer_state *out_next_state
)
{
	t_ft_json_tokenizer_state_number *const	result
		= malloc(sizeof(t_ft_json_tokenizer_state_number));

	if (!result)
		return (true);
	result->current_digit = 1;
	result->value = 0;
	result->sign = 1;
	result->exp = 0;
	result->exp_sign = 1;
	out_next_state->data = result;
	out_next_state->state = FT_JSON_TOKENIZER_STATE_NUMBER_INTEGER;
	if (c == '-')
	{
		result->sign = -1;
		out_next_state->state = FT_JSON_TOKENIZER_STATE_NUMBER_SIGN;
	}
	else if (c == '0')
		out_next_state->state = FT_JSON_TOKENIZER_STATE_NUMBER_ZERO;
	else
		result->value = c - '0';
	return (false);
}

static t_err	transition_to_string(
	t_ft_json_tokenizer_state *out_next_state
)
{
	t_ft_json_tokenizer_state_string *const	result
		= malloc(sizeof(t_ft_json_tokenizer_state_string));
	t_stringbuilder *const					stringbuilder
		= new_stringbuilder(1024);

	if (!result || !stringbuilder)
	{
		free(result);
		if (stringbuilder)
			stringbuilder_free(stringbuilder);
		return (true);
	}
	result->stringbuilder = stringbuilder;
	*out_next_state = (t_s){FT_JSON_TOKENIZER_STATE_STRING_ANY, result};
	return (false);
}

t_err	ft_json_tokenize_default(
	char c,
	t_ft_json_token_list *list,
	void *data,
	t_ft_json_tokenizer_state *out_next_state
)
{
	(void)data;
	*out_next_state = (t_s){FT_JSON_TOKENIZER_STATE_ERROR, NULL};
	if (!c
		|| c == '[' || c == ']' || c == '{' || c == '}' || c == ':' || c == ',')
		return (special_token(c, list, out_next_state));
	else if (c == 't')
		*out_next_state = (t_s){FT_JSON_TOKENIZER_STATE_KEYWORD_T, NULL};
	else if (c == 'f')
		*out_next_state = (t_s){FT_JSON_TOKENIZER_STATE_KEYWORD_F, NULL};
	else if (c == 'n')
		*out_next_state = (t_s){FT_JSON_TOKENIZER_STATE_KEYWORD_N, NULL};
	else if (c == ' ' || c == '\n' || c == '\r' || c == '\t')
		*out_next_state = (t_s){FT_JSON_TOKENIZER_STATE_DEFAULT, NULL};
	else if (c == '-' || ('0' <= c && c <= '9'))
		return (transition_to_number(c, out_next_state));
	else if (c == '"')
		return (transition_to_string(out_next_state));
	return (false);
}
