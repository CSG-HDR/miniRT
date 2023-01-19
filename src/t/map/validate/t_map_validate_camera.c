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

bool	t_map_validate_camera(t_ft_json value)
{
	return (
		true
		&& ft_json_is_dict(value)
		&& ft_json_dict_has_key(value, "position")
		&& t_map_validate_position(ft_json_get_dict(value, "position"))
		&& ft_json_dict_has_key(value, "rotation")
		&& t_map_validate_rotation(ft_json_get_dict(value, "rotation"))
		&& ft_json_dict_has_key(value, "fov")
		&& ft_json_is_number(ft_json_get_dict(value, "fov"))
		&& ft_json_get_number(ft_json_get_dict(value, "fov")) > 0
		&& ft_json_get_number(ft_json_get_dict(value, "fov")) < 0.5
	);
}
