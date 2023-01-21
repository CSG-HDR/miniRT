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
#include "t_map_validate.h"

static t_err	parse_point(
	t_ft_json value,
	t_map_light_point **out
)
{
	t_map_light_point *const	result
		= wrap_malloc(sizeof(t_map_light_point));

	if (!result)
		return (true);
	result->type = T_MAP_LIGHT_POINT;
	t_map_parse_point(value, &result->point);
	*out = result;
	return (false);
}

static t_err	parse_directional(
	t_ft_json value,
	t_map_light_directional **out
)
{
	t_map_light_directional *const	result
		= wrap_malloc(sizeof(t_map_light_directional));

	if (!result)
		return (true);
	result->type = T_MAP_LIGHT_DIRECTIONAL;
	t_map_parse_directional(value, &result->directional);
	*out = result;
	return (false);
}

static t_err	parse_spot(
	t_ft_json value,
	t_map_light_spot **out
)
{
	t_map_light_spot *const	result
		= wrap_malloc(sizeof(t_map_light_spot));

	if (!result)
		return (true);
	result->type = T_MAP_LIGHT_SPOT;
	t_map_parse_spot(value, &result->spot);
	*out = result;
	return (false);
}

t_err	t_map_parse_light(t_ft_json value, t_map_light *out)
{
	if (t_map_validate_has_type(value, "point"))
		return (parse_point(value, &out->point));
	if (t_map_validate_has_type(value, "directional"))
		return (parse_directional(value, &out->directional));
	return (parse_spot(value, &out->spot));
}
