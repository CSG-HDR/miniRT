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

static bool	is_constructive(const char *type)
{
	return (
		false
		|| ft_cstring_equals(type, "union")
		|| ft_cstring_equals(type, "intersection")
		|| ft_cstring_equals(type, "difference")
	);
}

t_err	t_map_parse_model(t_ft_json value, t_map_model **out)
{
	t_map_model *const	result = wrap_malloc(sizeof(t_map_model));

	if (is_constructive(ft_json_get_string(ft_json_get_dict(value, "type"))))
	{
		result->constructive.type = T_MAP_MODEL_TYPE_CONSTRUCTIVE;
		if (t_map_parse_constructive(value, &result->constructive.constructive))
		{
			wrap_free(result);
			return (true);
		}
		*out = result;
		return (false);
	}
	else
	{
		result->constructive.type = T_MAP_MODEL_TYPE_PRIMITIVE;
		if (t_map_parse_primitive(value, &result->primitive.primitive))
		{
			wrap_free(result);
			return (true);
		}
		*out = result;
		return (false);
	}
}
