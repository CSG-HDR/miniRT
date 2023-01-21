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

static t_err	parse_point(
	t_ft_json value,
	t_map_light_point **out
)
{
	t_map_light_point *const	result
		= wrap_malloc(sizeof(t_map_light_point));

	if (!result)
		return (true);
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
	t_map_parse_spot(value, &result->spot);
	*out = result;
	return (false);
}

t_err	t_map_parse_light(t_ft_json value, t_map_light *out)
{
	if (ft_cstring_equals(ft_json_get_dict(value, "type"), "point"))
		return (parse_point(value, &out->point));
	if (ft_cstring_equals(ft_json_get_dict(value, "type"), "directional"))
		return (parse_directional(value, &out->directional));
	return (parse_spot(value, &out->spot));
}
