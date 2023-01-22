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

#include "ft_json.h"

static bool	validate_size(t_ft_json value)
{
	return (
		true
		&& ft_json_is_list(value)
		&& ft_json_list_length(value) == 2
		&& ft_json_is_number(ft_json_get_list(value, 0))
		&& ft_json_get_number(ft_json_get_list(value, 0)) > 0
		&& ft_json_get_number(ft_json_get_list(value, 0))
		== (size_t)ft_json_get_number(ft_json_get_list(value, 0))
		&& ft_json_is_number(ft_json_get_list(value, 1))
		&& ft_json_get_number(ft_json_get_list(value, 1)) > 0
		&& ft_json_get_number(ft_json_get_list(value, 1))
		== (size_t)ft_json_get_number(ft_json_get_list(value, 1))
	);
}

static bool	validate_only(t_ft_json value)
{
	return (
		true
		&& ft_json_is_list(value)
		&& ft_json_list_length(value) == 4
		&& ft_json_is_number(ft_json_get_list(value, 0))
		&& ft_json_get_number(ft_json_get_list(value, 0)) <= 0
		&& ft_json_get_number(ft_json_get_list(value, 0))
		== (size_t)ft_json_get_number(ft_json_get_list(value, 0))
		&& ft_json_is_number(ft_json_get_list(value, 1))
		&& ft_json_get_number(ft_json_get_list(value, 1)) <= 0
		&& ft_json_get_number(ft_json_get_list(value, 1))
		== (size_t)ft_json_get_number(ft_json_get_list(value, 1))
		&& ft_json_is_number(ft_json_get_list(value, 2))
		&& ft_json_get_number(ft_json_get_list(value, 2)) <= 0
		&& ft_json_get_number(ft_json_get_list(value, 2))
		== (size_t)ft_json_get_number(ft_json_get_list(value, 2))
		&& ft_json_is_number(ft_json_get_list(value, 3))
		&& ft_json_get_number(ft_json_get_list(value, 3)) <= 0
		&& ft_json_get_number(ft_json_get_list(value, 3))
		== (size_t)ft_json_get_number(ft_json_get_list(value, 3))
	);
}

bool	t_map_validate_viewport(t_ft_json value)
{
	return (
		true
		&& ft_json_is_dict(value)
		&& ft_json_dict_has_key(value, "size")
		&& validate_size(ft_json_get_dict(value, "size"))
		&& (!ft_json_dict_has_key(value, "only")
			|| validate_only(ft_json_get_dict(value, "only")))
	);
}
