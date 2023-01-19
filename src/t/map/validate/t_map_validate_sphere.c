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

bool	t_map_validate_sphere(t_ft_json value)
{
	return (
		true
		&& ft_json_is_dict(value)
		&& ft_json_dict_has_key(value, "type")
		&& ft_json_is_string(ft_json_get_dict(value, "type"))
		&& ft_cstring_equals(
			ft_json_get_string(ft_json_get_dict(value, "type")), "sphere")
		&& ft_json_dict_has_key(value, "position")
		&& t_map_validate_position(ft_json_get_dict(value, "position"))
		&& ft_json_dict_has_key(value, "radius")
		&& ft_json_is_number(ft_json_get_dict(value, "radius"))
		&& ft_json_get_number(ft_json_get_dict(value, "radius")) > 0
		&& ft_json_dict_has_key(value, "material")
		&& t_map_validate_material(ft_json_get_dict(value, "material"))
	);
}
