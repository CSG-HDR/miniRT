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

static bool	validate_angle(t_ft_json value)
{
	return (
		true
		&& ft_json_is_list(value)
		&& ft_json_list_length(value) == 3
		&& ft_json_is_number(ft_json_get_list(value, 0))
		&& ft_json_get_number(ft_json_get_list(value, 0)) >= 0
		&& ft_json_get_number(ft_json_get_list(value, 0)) < 1
		&& ft_json_is_number(ft_json_get_list(value, 1))
		&& ft_json_get_number(ft_json_get_list(value, 1)) >= 0
		&& ft_json_get_number(ft_json_get_list(value, 1)) < 1
		&& ft_json_is_number(ft_json_get_list(value, 2))
		&& ft_json_get_number(ft_json_get_list(value, 2)) >= 0
		&& ft_json_get_number(ft_json_get_list(value, 2)) < 1
	);
}

static bool	validate_normal_obj(t_ft_json value)
{
	return (
		true
		&& ft_json_is_dict(value)
		&& ft_json_dict_has_key(value, "normal")
		&& t_map_validate_normal(ft_json_get_dict(value, "normal"))
	);
}

static bool	validate_angle_obj(t_ft_json value)
{
	return (
		true
		&& ft_json_is_dict(value)
		&& ft_json_dict_has_key(value, "angle")
		&& validate_angle(ft_json_get_dict(value, "angle"))
	);
}

bool	t_map_validate_rotation(t_ft_json value)
{
	return (validate_normal_obj(value) != validate_angle_obj(value));
}
