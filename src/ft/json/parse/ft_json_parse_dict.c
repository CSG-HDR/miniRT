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

static inline char	*ft_sd(const char *src)
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
		return (NULL);
	tmp = src;
	temp = result;
	while (*tmp)
		*temp++ = *tmp++;
	*temp = '\0';
	return (result);
}

static t_err	append_entry(
	t_ft_json_token_list_node **head,
	t_ft_json_value_dict *out
)
{
	t_ft_json_dict_node *const		node = malloc(sizeof(t_ft_json_dict_node));
	char *const						key = ft_sd((*head)->value.string->value);
	t_ft_json_value_internal *const	value
		= malloc(sizeof(t_ft_json_value_internal));

	*head = (*head)->next->next;
	if (!node || !key || !value || ft_json_parse_value(head, value))
	{
		free(node);
		free(key);
		free(value);
		return (true);
	}
	node->next = NULL;
	node->key = key;
	node->value = value;
	if (out->value.tail)
		out->value.tail->next = node;
	else
		out->value.head = node;
	out->value.tail = node;
	return (false);
}

static t_err	fill_entries(
	t_ft_json_token_list_node **head,
	t_ft_json_value_dict *out
)
{
	if (*(*head)->value.type == FT_JSON_TOKEN_TYPE_BRACE_CLOSE)
		return (false);
	if (append_entry(head, out))
		return (true);
	if (out->value.tail == FT_JSON_VALUE_TYPE_ERROR)
		return (false);
	while (out->value.tail->value->type != FT_JSON_VALUE_TYPE_ERROR
		&& *(*head)->value.type == FT_JSON_TOKEN_TYPE_COMMA
		&& *(*head)->next->value.type == FT_JSON_TOKEN_TYPE_STRING
		&& *(*head)->next->next->value.type == FT_JSON_TOKEN_TYPE_COLON
		&& ft_json_parse_next_is_value(*(*head)->next->next->next->value.type))
	{
		*head = (*head)->next;
		if (append_entry(head, out))
		{
			ft_json_value_dict_free(out);
			return (true);
		}
	}
	return (false);
}

t_err	ft_json_parse_dict(
	t_ft_json_token_list_node **head,
	t_ft_json_value_dict *out
)
{
	t_ft_json_token_list_node	*curr;

	curr = *head;
	if (!ft_json_parse_next_is_dict(*(*head)->value.type)
		|| (*(*head)->next->value.type != FT_JSON_TOKEN_TYPE_STRING
			&& *(*head)->next->value.type != FT_JSON_TOKEN_TYPE_BRACE_CLOSE))
	{
		out->type = FT_JSON_VALUE_TYPE_ERROR;
		return (false);
	}
	curr = curr->next;
	out->type = FT_JSON_VALUE_TYPE_DICT;
	out->value.head = NULL;
	out->value.tail = NULL;
	if (fill_entries(&curr, out))
		return (true);
	if (*curr->value.type != FT_JSON_TOKEN_TYPE_BRACE_CLOSE || (out->value.tail
			&& out->value.tail->value->type == FT_JSON_VALUE_TYPE_ERROR))
	{
		ft_json_value_dict_free(out);
		out->type = FT_JSON_VALUE_TYPE_ERROR;
		return (false);
	}
	*head = curr->next;
	return (false);
}
