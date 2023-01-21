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

t_err	t_map_parse_torus(t_ft_json value, t_map_torus *out)
{
	t_map_parse_position(ft_json_get_dict(value, "position"), &out->position);
	t_map_parse_size(ft_json_get_dict(value, "size"), &out->size);
	t_map_parse_rotation(ft_json_get_dict(value, "rotation"), &out->rotation);
	return (t_map_parse_get_optional_material(value, &out->material));
}
