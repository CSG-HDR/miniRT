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

bool	t_map_validate_ellipsoid(t_ft_json value)
{
	return (
		true
		&& t_map_validate_has_type(value, "ellipsoid")
		&& t_map_validate_has_position(value)
		&& t_map_validate_has_size(value)
		&& t_map_validate_has_rotation(value)
		&& t_map_validate_has_optional_material(value)
	);
}
