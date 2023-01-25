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

t_err	t_map_parse_plane(t_ft_json value, t_map_plane *out)
{
	t_map_parse_position(
		ft_json_get_dict(value, "position"), &out->position);
	t_map_parse_normal(
		ft_json_get_dict(value, "normal"), &out->normal);
	t_map_parse_color_material(
		ft_json_get_dict(value, "material"), &out->material);
	return (t_map_parse_optional_limit(value, &out->limit));
}
