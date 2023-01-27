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
#include "t_f3.h"
#include "t_map.h"

void	t_map_parse_rotation(t_ft_json value, t_map_rotation *out)
{
	t_f	yaw;
	t_f	pitch;
	t_f	roll;

	yaw = (t_f)ft_json_get_number(ft_json_get_list(value, 0));
	pitch = (t_f)ft_json_get_number(ft_json_get_list(value, 1));
	roll = (t_f)ft_json_get_number(ft_json_get_list(value, 2));
	if (yaw < 0)
		yaw += (t_f)1;
	if (pitch < 0)
		pitch += (t_f)1;
	if (roll < 0)
		roll += (t_f)1;
	out->x = t_f_rad(yaw);
	out->y = t_f_rad(pitch);
	out->z = t_f_rad(roll);
}
