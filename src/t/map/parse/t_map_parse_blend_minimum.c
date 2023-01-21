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

t_err	t_map_parse_blend_minimum(t_ft_json value, t_map_blend_minimum *out)
{
	out->type = T_MAP_BLEND_TYPE_MINIMUM;
	return (
		t_map_parse_colors(ft_json_get_dict(value, "children"),
			&out->children, &out->children_count)
	);
}
