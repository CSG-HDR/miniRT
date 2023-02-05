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

static void	t_map_parse_get_optional_direction(
	t_ft_json value,
	t_map_normal *out
)
{
	if (!ft_json_dict_has_key(value, "direction"))
		*out = (t_map_normal){(t_f)0, (t_f)0, (t_f)1};
	else
		t_map_parse_normal(ft_json_get_dict(value, "direction"), out);
}

void	t_map_parse_plane(t_ft_json value, t_map_plane *out)
{
	t_map_parse_get_position(value, &out->position);
	t_map_parse_get_optional_direction(value, &out->normal);
	t_map_parse_get_optional_color_material(value, &out->material);
}
