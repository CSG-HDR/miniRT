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
#include "ft_cstring.h"
#include "ft_json.h"
#include "t_map.h"

static t_err	parse_color(
	t_ft_json value,
	t_map_color_color **out
)
{
	t_map_color_color *const	result
		= wrap_malloc(sizeof(t_map_color_color));

	if (!result)
		return (true);
	result->type = T_MAP_COLOR_TYPE_COLOR;
	t_map_parse_material_color(value, &result->color);
	*out = result;
	return (false);
}

static t_err	parse_texture(
	t_ft_json value,
	t_map_color_texture **out
)
{
	t_map_color_texture *const	result
		= wrap_malloc(sizeof(t_map_color_texture));

	if (!result)
		return (true);
	result->type = T_MAP_COLOR_TYPE_TEXTURE;
	if (t_map_parse_texture(value, &result->texture))
	{
		wrap_free(result);
		return (true);
	}
	*out = result;
	return (false);
}

t_err	t_map_parse_color(t_ft_json value, t_map_color *out)
{
	if (ft_cstring_equals(ft_json_get_dict(value, "type"), "color"))
		return (parse_color(value, &out->color));
	return (parse_texture(value, &out->texture));
}
