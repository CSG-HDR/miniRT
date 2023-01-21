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

#include "wrap.h"
#include "ft_json.h"
#include "t_map.h"

t_err	t_map_parse_normal_map(t_ft_json value, t_map_normal_map *out)
{
	if (ft_json_is_dict(value))
	{
		out->color = wrap_malloc(sizeof(t_map_normal_map_color));
		if (!out->color)
			return (true);
		out->color->type = T_MAP_NORMAL_MAP_TYPE_COLOR;
		if (t_map_parse_color(value, &out->color->color))
		{
			wrap_free(out->color);
			return (true);
		}
		return (false);
	}
	else
	{
		out->normal = wrap_malloc(sizeof(t_map_normal_map_normal));
		if (!out->color)
			return (true);
		out->color->type = T_MAP_NORMAL_MAP_TYPE_NORMAL;
		t_map_parse_normal(value, &out->normal->normal);
		return (false);
	}
}
