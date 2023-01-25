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

#include "t_f3.h"
#include "t_map_parse.h"

#include "ft_json.h"
#include "t_f.h"
#include "t_map.h"
#include "t_map_validate.h"

void	t_map_parse_camera_rotation(t_ft_json value, t_map_camera *out)
{
	t_map_normal	direction;
	t_map_position	position;

	if (t_map_validate_has_type(value, "rotation"))
	{
		t_map_parse_get_rotation(value, &out->rotation);
		return ;
	}
	if (t_map_validate_has_type(value, "direction"))
	{
		t_map_parse_get_direction(value, &direction);
	}
	else
	{
		t_map_parse_get_position(value, &position);
		direction = t_f3_unit(t_f3_sub(position, out->position));
	}
	out->rotation = t_f3_to_angle(direction);
}
