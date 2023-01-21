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

bool	t_map_validate_sphere(t_ft_json value)
{
	return (
		true
		&& t_map_validate_has_type(value, "sphere")
		&& t_map_validate_has_position(value)
		&& ft_json_dict_has_key(value, "radius")
		&& ft_json_is_number(ft_json_get_dict(value, "radius"))
		&& ft_json_get_number(ft_json_get_dict(value, "radius")) > 0
		&& t_map_validate_has_optional_material(value)
	);
}
