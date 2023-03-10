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

static t_err	parse_union(
	t_ft_json value,
	t_map_constructive_union **out
)
{
	t_map_constructive_union *const	result
		= wrap_malloc(sizeof(t_map_constructive_union));

	if (!result)
		return (true);
	result->type = T_MAP_CONSTRUCTIVE_TYPE_UNION;
	if (t_map_parse_union(value, &result->_union))
	{
		wrap_free(result);
		return (true);
	}
	*out = result;
	return (false);
}

static t_err	parse_intersection(
	t_ft_json value,
	t_map_constructive_intersection **out
)
{
	t_map_constructive_intersection *const	result
		= wrap_malloc(sizeof(t_map_constructive_intersection));

	if (!result)
		return (true);
	result->type = T_MAP_CONSTRUCTIVE_TYPE_INTERSECTION;
	if (t_map_parse_intersection(value, &result->intersection))
	{
		wrap_free(result);
		return (true);
	}
	*out = result;
	return (false);
}

static t_err	parse_difference(
	t_ft_json value,
	t_map_constructive_difference **out
)
{
	t_map_constructive_difference *const	result
		= wrap_malloc(sizeof(t_map_constructive_difference));

	if (!result)
		return (true);
	result->type = T_MAP_CONSTRUCTIVE_TYPE_DIFFERENCE;
	if (t_map_parse_difference(value, &result->difference))
	{
		wrap_free(result);
		return (true);
	}
	*out = result;
	return (false);
}

t_err	t_map_parse_constructive(t_ft_json value, t_map_constructive *out)
{
	if (t_map_validate_has_type(value, "union"))
		return (parse_union(value, &out->_union));
	if (t_map_validate_has_type(value, "intersection"))
		return (parse_intersection(value, &out->intersection));
	return (parse_difference(value, &out->difference));
}
