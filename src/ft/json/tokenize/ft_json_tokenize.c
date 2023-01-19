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

#include <stddef.h>

static const t_ft_json_tokenizer_state_function	g_state_functions[] = {
	ft_json_tokenize_default,
	ft_json_tokenize_keyword_t,
	ft_json_tokenize_keyword_tr,
	ft_json_tokenize_keyword_tru,
	ft_json_tokenize_keyword_f,
	ft_json_tokenize_keyword_fa,
	ft_json_tokenize_keyword_fal,
	ft_json_tokenize_keyword_fals,
	ft_json_tokenize_keyword_n,
	ft_json_tokenize_keyword_nu,
	ft_json_tokenize_keyword_nul,
	ft_json_tokenize_string_any,
	ft_json_tokenize_string_backslash,
	ft_json_tokenize_string_x0,
	ft_json_tokenize_string_x1,
	ft_json_tokenize_number_sign,
	ft_json_tokenize_number_zero,
	ft_json_tokenize_number_integer,
	ft_json_tokenize_number_dot,
	ft_json_tokenize_number_fraction,
	ft_json_tokenize_number_e,
	ft_json_tokenize_number_e_sign,
	ft_json_tokenize_number_e_digit,
};

typedef t_ft_json_tokenizer_state				t_s;

t_err	ft_json_tokenize(
	const char *str,
	t_ft_json_token_list *out
)
{
	t_s		current_state;
	size_t	i;

	current_state.state = FT_JSON_TOKENIZER_STATE_DEFAULT;
	current_state.data = NULL;
	*out = (t_ft_json_token_list){NULL, NULL};
	i = -1;
	while (current_state.state != FT_JSON_TOKENIZER_STATE_ERROR
		&& (i++ == (size_t)-1 || str[i - 1]))
	{
		if (g_state_functions[current_state.state](
			str[i], out, current_state.data, &current_state))
		{
			ft_json_tokenize_free(*out);
			return (true);
		}
	}
	if (current_state.state == FT_JSON_TOKENIZER_STATE_ERROR)
	{
		ft_json_tokenize_free(*out);
		*out = (t_ft_json_token_list){NULL, NULL};
	}
	return (false);
}
