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

bool	t_map_validate_spot(t_ft_json value)
{
	return (
		true
		&& ft_json_is_dict(value)
		&& ft_json_dict_has_key(value, "type")
		&& ft_json_is_string(ft_json_get_dict(value, "type"))
		&& ft_cstring_equals(
			ft_json_get_string(ft_json_get_dict(value, "type")), "spot")
		&& ft_json_dict_has_key(value, "color")
		&& t_map_validate_light_color(ft_json_get_dict(value, "color"))
		&& ft_json_dict_has_key(value, "position")
		&& t_map_validate_position(ft_json_get_dict(value, "position"))
		&& ft_json_dict_has_key(value, "angle")
		&& ft_json_is_number(ft_json_get_dict(value, "angle"))
		&& ft_json_get_number(ft_json_get_dict(value, "angle")) > 0
		&& ft_json_get_number(ft_json_get_dict(value, "angle")) < 1
		&& ft_json_dict_has_key(value, "direction")
		&& t_map_validate_normal(ft_json_get_dict(value, "direction"))
		&& (!ft_json_dict_has_key(value, "range") || (true
				&& ft_json_is_number(ft_json_get_dict(value, "range"))
				&& ft_json_get_number(ft_json_get_dict(value, "range")) > 0))
	);
}
