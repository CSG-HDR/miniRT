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

t_err	ft_json_tokenize_keyword_fals(
	char c,
	t_ft_json_token_list *list,
	void *data,
	t_ft_json_tokenizer_state *out_next_state
)
{
	(void)list;
	(void)data;
	if (c == 'e')
	{
		if (ft_json_tokenize_add_simple_token(list, FT_JSON_TOKEN_TYPE_FALSE))
			return (true);
		out_next_state->state = FT_JSON_TOKENIZER_STATE_DEFAULT;
	}
	else
		out_next_state->state = FT_JSON_TOKENIZER_STATE_ERROR;
	return (false);
}
