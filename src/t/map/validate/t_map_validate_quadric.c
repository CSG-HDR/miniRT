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

static bool	valid_list(t_ft_json value)
{
	return (
		true
		&& t_map_validate_has_number_list(value, 0)
		&& ft_json_get_number(ft_json_get_list(value, 0)) != 0
		&& t_map_validate_has_number_list(value, 1)
		&& ft_json_get_number(ft_json_get_list(value, 1)) != 0
		&& t_map_validate_has_number_list(value, 2)
		&& ft_json_get_number(ft_json_get_list(value, 2)) != 0
		&& t_map_validate_has_number_list(value, 3)
		&& t_map_validate_has_number_list(value, 4)
		&& t_map_validate_has_number_list(value, 5)
		&& t_map_validate_has_number_list(value, 6)
		&& t_map_validate_has_number_list(value, 7)
		&& t_map_validate_has_number_list(value, 8)
		&& t_map_validate_has_number_list(value, 9)
	);
}

static bool	valid_dict(t_ft_json value)
{
	return (
		true
		&& t_map_validate_has_number_dict(value, "A")
		&& ft_json_get_number(ft_json_get_dict(value, "A")) != 0
		&& t_map_validate_has_number_dict(value, "B")
		&& ft_json_get_number(ft_json_get_dict(value, "B")) != 0
		&& t_map_validate_has_number_dict(value, "C")
		&& ft_json_get_number(ft_json_get_dict(value, "C")) != 0
		&& t_map_validate_has_optional_number(value, "D")
		&& t_map_validate_has_optional_number(value, "E")
		&& t_map_validate_has_optional_number(value, "F")
		&& t_map_validate_has_optional_number(value, "G")
		&& t_map_validate_has_optional_number(value, "H")
		&& t_map_validate_has_optional_number(value, "I")
		&& t_map_validate_has_optional_number(value, "J")
	);
}

static bool	has_properties(t_ft_json value)
{
	if (ft_json_is_list(value))
		return (valid_list(value));
	if (ft_json_is_dict(value))
		return (valid_dict(value));
	return (false);
}

bool	t_map_validate_quadric(t_ft_json value)
{
	return (
		true
		&& has_properties(value)
		&& (!ft_json_dict_has_key(value, "material")
			|| t_map_validate_color_material(
				ft_json_get_dict(value, "material")))
		&& (!ft_json_dict_has_key(value, "limit")
			|| t_map_validate_model(
				ft_json_get_dict(value, "limit")))
	);
}
