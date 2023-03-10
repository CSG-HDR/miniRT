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
#include "t_f.h"
#include "t_map.h"

void	t_map_parse_spot(t_ft_json value, t_map_spot *out)
{
	t_map_parse_get_color(value, &out->color);
	t_map_parse_get_position(value, &out->position);
	t_map_parse_get_direction(value, &out->direction);
	out->angle = t_f_rad(
			(t_f)ft_json_get_number(ft_json_get_dict(value, "angle")));
	t_map_parse_get_optional_range(value, &out->has_range, &out->range);
}
