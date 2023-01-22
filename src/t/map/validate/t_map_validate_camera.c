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

static bool	has_fov(t_ft_json value)
{
	return (
		true
		&& ft_json_dict_has_key(value, "fov")
		&& ft_json_is_number(ft_json_get_dict(value, "fov"))
		&& ft_json_get_number(ft_json_get_dict(value, "fov")) > 0
		&& ft_json_get_number(ft_json_get_dict(value, "fov")) < 0.5
	);
}

static bool	has_optional_fov_type(t_ft_json value)
{
	if (!ft_json_dict_has_key(value, "fovType"))
		return (true);
	if (!ft_json_is_string(ft_json_get_dict(value, "fovType")))
		return (false);
	if (
		true
		&& !ft_cstring_equals(
			ft_json_get_string(ft_json_get_dict(value, "fovType")), "max")
		&& !ft_cstring_equals(
			ft_json_get_string(ft_json_get_dict(value, "fovType")), "min")
		&& !ft_cstring_equals(
			ft_json_get_string(ft_json_get_dict(value, "fovType")), "x")
		&& !ft_cstring_equals(
			ft_json_get_string(ft_json_get_dict(value, "fovType")), "y")
	)
		return (false);
	return (true);
}

bool	t_map_validate_camera(t_ft_json value)
{
	return (
		true
		&& ft_json_is_dict(value)
		&& t_map_validate_has_position(value)
		&& t_map_validate_has_rotation(value)
		&& has_fov(value)
		&& has_optional_fov_type(value)
	);
}
