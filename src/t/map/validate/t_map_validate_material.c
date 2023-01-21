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

bool	t_map_validate_material(t_ft_json value)
{
	return (
		true
		&& ft_json_is_dict(value)
		&& ft_json_dict_has_key(value, "ambient")
		&& t_map_validate_color(ft_json_get_dict(value, "ambient"))
		&& ft_json_dict_has_key(value, "diffuse")
		&& t_map_validate_color(ft_json_get_dict(value, "diffuse"))
		&& ft_json_dict_has_key(value, "specular")
		&& t_map_validate_color(ft_json_get_dict(value, "specular"))
		&& ft_json_dict_has_key(value, "specularLobe")
		&& ft_json_is_number(ft_json_get_dict(value, "specularLobe"))
		&& (!ft_json_dict_has_key(value, "normal")
			|| t_map_validate_normal_map(ft_json_get_dict(value, "normal")))
	);
}
