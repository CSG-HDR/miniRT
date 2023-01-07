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

typedef t_ft_json_tokenizer_state	t_s;

t_err	ft_json_tokenize_number_dot(
	char c,
	t_ft_json_token_list *list,
	void *data,
	t_ft_json_tokenizer_state *out_next_state
)
{
	t_ft_json_tokenizer_state_number *const	d = data;

	(void)list;
	if ('0' <= c && c <= '9')
	{
		d->current_digit /= 10;
		d->value += d->current_digit * (c - '0');
		*out_next_state = (t_s){FT_JSON_TOKENIZER_STATE_NUMBER_FRACTION, data};
		return (false);
	}
	free(data);
	*out_next_state = (t_s){FT_JSON_TOKENIZER_STATE_ERROR, NULL};
	return (false);
}
