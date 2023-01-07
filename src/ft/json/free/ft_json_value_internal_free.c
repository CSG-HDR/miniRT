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

void	ft_json_value_internal_free(
	t_ft_json_value_internal *value
)
{
	if (value->type == FT_JSON_VALUE_TYPE_STRING)
		ft_json_value_string_free(&value->string);
	else if (value->type == FT_JSON_VALUE_TYPE_LIST)
		ft_json_value_list_free(&value->list);
	else if (value->type == FT_JSON_VALUE_TYPE_DICT)
		ft_json_value_dict_free(&value->dict);
}
