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

#include "t_map_parse.h"

#include "ft_json.h"
#include "t_map.h"
#include "t_map_free.h"

t_err	t_map_parse_ellipsoid(t_ft_json value, t_map_ellipsoid *out)
{
	t_map_parse_get_optional_position(value, &out->position);
	t_map_parse_get_optional_size(value, &out->size);
	t_map_parse_get_optional_rotation(value, &out->rotation);
	return (t_map_parse_get_optional_material(value, &out->material));
}
