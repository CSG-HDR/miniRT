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

#include <stddef.h>

#include "ft_json.h"
#include "t_map.h"

void	t_map_parse_viewport(t_ft_json value, t_map_viewport *out)
{
	out->width = (size_t)ft_json_get_number(
			ft_json_get_list(ft_json_get_dict(value, "size"), 0));
	out->height = (size_t)ft_json_get_number(
			ft_json_get_list(ft_json_get_dict(value, "size"), 0));
	if (ft_json_dict_has_key(value, "only"))
	{
		out->start_x = (size_t)ft_json_get_number(
				ft_json_get_list(ft_json_get_dict(value, "only"), 0));
		out->start_y = (size_t)ft_json_get_number(
				ft_json_get_list(ft_json_get_dict(value, "only"), 1));
		out->end_x = (size_t)ft_json_get_number(
				ft_json_get_list(ft_json_get_dict(value, "only"), 2));
		out->end_y = (size_t)ft_json_get_number(
				ft_json_get_list(ft_json_get_dict(value, "only"), 3));
	}
	else
	{
		out->start_x = 0;
		out->start_y = 0;
		out->end_x = out->width;
		out->end_y = out->height;
	}
	out->actual_width = out->end_x - out->start_x;
	out->actual_height = out->end_y - out->start_y;
}
