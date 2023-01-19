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

#include "t_map_validate.h"

#include <stdbool.h>

#include "ft_cstring.h"
#include "ft_json.h"

static bool	validate_children(t_ft_json value)
{
	size_t	count;

	if (!ft_json_is_list(value))
		return (false);
	count = ft_json_list_length(value);
	while (count--)
		if (!t_map_validate_model(value))
			return (false);
	return (true);
}

bool	t_map_validate_intersection(t_ft_json value)
{
	return (
		true
		&& ft_json_is_dict(value)
		&& ft_json_dict_has_key(value, "type")
		&& ft_json_is_string(ft_json_get_dict(value, "type"))
		&& ft_cstring_equals(
			ft_json_get_string(ft_json_get_dict(value, "type")), "intersection")
		&& ft_json_dict_has_key(value, "children")
		&& validate_children(ft_json_get_dict(value, "children"))
	);
}
