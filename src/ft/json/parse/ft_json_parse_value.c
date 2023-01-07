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

static inline t_err	ft_strdup(const char *src, char **out)
{
	size_t		length;
	char		*result;
	const char	*tmp;
	char		*temp;

	length = 0;
	tmp = src;
	while (*tmp)
	{
		tmp++;
		length++;
	}
	result = malloc(length + 1);
	if (!result)
		return (true);
	tmp = src;
	temp = result;
	while (*tmp)
		*temp++ = *tmp++;
	*temp = '\0';
	*out = result;
	return (false);
}

static t_err	special(
	t_ft_json_token_list_node **head,
	t_ft_json_value_internal *out
)
{
	t_err	result;

	result = false;
	if (*(*head)->value.type == FT_JSON_TOKEN_TYPE_NULL)
		out->type = FT_JSON_VALUE_TYPE_NULL;
	else if (*(*head)->value.type == FT_JSON_TOKEN_TYPE_TRUE
		|| *(*head)->value.type == FT_JSON_TOKEN_TYPE_FALSE)
	{
		out->type = FT_JSON_VALUE_TYPE_BOOLEAN;
		out->boolean.value = *(*head)->value.type == FT_JSON_TOKEN_TYPE_TRUE;
	}
	else if (*(*head)->value.type == FT_JSON_TOKEN_TYPE_NUMBER)
	{
		out->type = FT_JSON_VALUE_TYPE_NUMBER;
		out->number.value = (*head)->value.number->value;
	}
	else if (*(*head)->value.type == FT_JSON_TOKEN_TYPE_STRING)
	{
		out->type = FT_JSON_VALUE_TYPE_STRING;
		result = ft_strdup((*head)->value.string->value, &out->string.value);
	}
	else
		return (true);
	*head = (*head)->next;
	return (result);
}

t_err	ft_json_parse_value(
	t_ft_json_token_list_node **head,
	t_ft_json_value_internal *out
)
{
	if (!ft_json_parse_next_is_value(*(*head)->value.type))
	{
		out->type = FT_JSON_VALUE_TYPE_ERROR;
		return (false);
	}
	if (ft_json_parse_next_is_list(*(*head)->value.type))
		return (ft_json_parse_list(head, &out->list));
	if (ft_json_parse_next_is_dict(*(*head)->value.type))
		return (ft_json_parse_dict(head, &out->dict));
	return (special(head, out));
}
