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

bool	validate_material(t_ft_json value)
{
	if (t_map_validate_material(value))
		return (true);
	return (
		true
		&& ft_json_is_list(value)
		&& ft_json_list_length(value) == 6
		&& t_map_validate_material(ft_json_get_list(value, 0))
		&& t_map_validate_material(ft_json_get_list(value, 1))
		&& t_map_validate_material(ft_json_get_list(value, 2))
		&& t_map_validate_material(ft_json_get_list(value, 3))
		&& t_map_validate_material(ft_json_get_list(value, 4))
		&& t_map_validate_material(ft_json_get_list(value, 5))
	);
}

bool	t_map_validate_cube(t_ft_json value)
{
	return (
		true
		&& ft_json_is_dict(value)
		&& ft_json_dict_has_key(value, "type")
		&& ft_json_is_string(ft_json_get_dict(value, "type"))
		&& ft_cstring_equals(
			ft_json_get_string(ft_json_get_dict(value, "type")), "cube")
		&& ft_json_dict_has_key(value, "position")
		&& t_map_validate_position(ft_json_get_dict(value, "position"))
		&& ft_json_dict_has_key(value, "size")
		&& t_map_validate_size(ft_json_get_dict(value, "size"))
		&& ft_json_dict_has_key(value, "rotation")
		&& t_map_validate_rotation(ft_json_get_dict(value, "rotation"))
		&& ft_json_dict_has_key(value, "material")
		&& validate_material(ft_json_get_dict(value, "material"))
	);
}
