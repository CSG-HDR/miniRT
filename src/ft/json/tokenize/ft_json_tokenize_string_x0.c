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

typedef t_ft_json_tokenizer_state			t_s;
typedef t_ft_json_tokenizer_state_string	t_x;

static unsigned char	from_hex(char c)
{
	if ('0' <= c && c <= '9')
		return (c - '0');
	if ('a' <= c && c <= 'f')
		return (c - 'a' + 10);
	if ('A' <= c && c <= 'F')
		return (c - 'A' + 10);
	return (-1);
}

t_err	ft_json_tokenize_string_x0(
	char c,
	t_ft_json_token_list *list,
	void *data,
	t_ft_json_tokenizer_state *out_next_state
)
{
	const unsigned char	value = from_hex(c);

	(void)list;
	if (value == (unsigned char)-1)
	{
		stringbuilder_free(((t_x *)data)->stringbuilder);
		free(data);
		*out_next_state = (t_s){FT_JSON_TOKENIZER_STATE_ERROR, NULL};
		return (false);
	}
	*out_next_state = (t_s){FT_JSON_TOKENIZER_STATE_STRING_X1, data};
	((t_x *)data)->x = value;
	return (false);
}
