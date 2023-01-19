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

static char	unescape(char c)
{
	if (c == '\"' || c == '\\' || c == '/')
		return (c);
	if (c == 'b')
		return ('\b');
	if (c == 'f')
		return ('\f');
	if (c == 'n')
		return ('\n');
	if (c == 'r')
		return ('\r');
	if (c == 't')
		return ('\t');
	return (0);
}

t_err	ft_json_tokenize_string_backslash(
	char c,
	t_ft_json_token_list *list,
	void *data,
	t_ft_json_tokenizer_state *out_next_state
)
{
	const char	next = unescape(c);

	(void)list;
	if (c == 'x')
	{
		*out_next_state = (t_s){FT_JSON_TOKENIZER_STATE_STRING_X0, data};
		return (false);
	}
	if (c == 'u' || !c)
	{
		stringbuilder_free(((t_x *)data)->stringbuilder);
		free(data);
		*out_next_state = (t_s){FT_JSON_TOKENIZER_STATE_ERROR, NULL};
		return (c == 'u');
	}
	*out_next_state = (t_s){FT_JSON_TOKENIZER_STATE_STRING_ANY, data};
	if (stringbuilder_append_char(((t_x *)data)->stringbuilder, next))
	{
		stringbuilder_free(((t_x *)data)->stringbuilder);
		free(data);
		return (true);
	}
	return (false);
}
