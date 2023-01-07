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
#include "ft_types_char.h"

typedef t_ft_json_tokenizer_state			t_s;
typedef t_ft_json_tokenizer_state_string	t_x;

t_err	ft_json_tokenize_string_any(
	char c,
	t_ft_json_token_list *list,
	void *data,
	t_ft_json_tokenizer_state *out_next_state
)
{
	if (c == '"')
	{
		*out_next_state = (t_s){FT_JSON_TOKENIZER_STATE_DEFAULT, NULL};
		return (ft_json_tokenize_add_string_token(list, (t_x *)data));
	}
	else if (c == '\\')
	{
		*out_next_state = (t_s){FT_JSON_TOKENIZER_STATE_STRING_BACKSLASH, data};
		return (false);
	}
	else if (ft_types_char_cntrl(c))
	{
		*out_next_state = (t_s){FT_JSON_TOKENIZER_STATE_ERROR, NULL};
		return (false);
	}
	*out_next_state = (t_s){FT_JSON_TOKENIZER_STATE_STRING_ANY, data};
	if (stringbuilder_append_char(((t_x *)data)->stringbuilder, c))
	{
		stringbuilder_free(((t_x *)data)->stringbuilder);
		free(data);
		return (true);
	}
	return (false);
}
