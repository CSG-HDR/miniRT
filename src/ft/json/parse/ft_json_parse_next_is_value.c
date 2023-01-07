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

bool	ft_json_parse_next_is_value(t_ft_json_token_type token_type)
{
	return (
		false
		|| token_type == FT_JSON_TOKEN_TYPE_NULL
		|| token_type == FT_JSON_TOKEN_TYPE_FALSE
		|| token_type == FT_JSON_TOKEN_TYPE_TRUE
		|| token_type == FT_JSON_TOKEN_TYPE_NUMBER
		|| token_type == FT_JSON_TOKEN_TYPE_STRING
		|| ft_json_parse_next_is_list(token_type)
		|| ft_json_parse_next_is_dict(token_type)
	);
}
