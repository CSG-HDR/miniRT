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

t_err	ft_json_parse_internal(
	const char *str,
	t_ft_json_value_internal *out
)
{
	t_ft_json_token_list		token_list;
	t_ft_json_token_list_node	*head;

	if (ft_json_tokenize(str, &token_list))
		return (true);
	if (!token_list.head)
	{
		out->type = FT_JSON_VALUE_TYPE_ERROR;
		return (false);
	}
	head = token_list.head;
	if (ft_json_parse_value(&head, out))
	{
		ft_json_token_list_free(token_list);
		return (true);
	}
	if (*head->value.type != FT_JSON_TOKEN_TYPE_EOF)
	{
		ft_json_token_list_free(token_list);
		ft_json_value_internal_free(out);
		out->type = FT_JSON_VALUE_TYPE_ERROR;
		return (false);
	}
	ft_json_token_list_free(token_list);
	return (false);
}
