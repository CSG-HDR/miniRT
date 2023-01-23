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

static bool	is_rotation(t_ft_json value)
{
	return (
		true
		&& ft_json_dict_has_key(value, "rotation")
		&& t_map_validate_rotation(ft_json_get_dict(value, "rotation"))
	);
}

static bool	is_normal(t_ft_json value)
{
	return (
		true
		&& ft_json_dict_has_key(value, "normal")
		&& t_map_validate_normal(ft_json_get_dict(value, "normal"))
	);
}

static bool	is_look_at(t_ft_json value)
{
	return (
		true
		&& ft_json_dict_has_key(value, "lookAt")
		&& t_map_validate_position(ft_json_get_dict(value, "lookAt"))
	);
}

static bool	is(t_ft_json value)
{
	return (false
		|| is_rotation(value)
		|| is_normal(value)
		|| is_look_at(value)
	);
}

bool	t_map_validate_camera_rotation(t_ft_json value)
{
	return (
		true
		&& ft_json_is_dict(value)
		&& ft_json_dict_has_key(value, "rotation")
		&& ft_json_is_dict(ft_json_get_dict(value, "rotation"))
		&& is(ft_json_get_dict(value, "rotation"))
	);
}
