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

static t_err	parse_sphere(
	t_ft_json value,
	t_map_primitive_sphere **out
)
{
	t_map_primitive_sphere *const	result
		= wrap_malloc(sizeof(t_map_primitive_sphere));

	if (!result)
		return (true);
	if (t_map_parse_sphere(value, &result->sphere))
	{
		wrap_free(result);
		return (true);
	}
	*out = result;
	return (false);
}

static t_err	parse_cube(
	t_ft_json value,
	t_map_primitive_cube **out
)
{
	t_map_primitive_cube *const	result
		= wrap_malloc(sizeof(t_map_primitive_cube));

	if (!result)
		return (true);
	if (t_map_parse_cube(value, &result->cube))
	{
		wrap_free(result);
		return (true);
	}
	*out = result;
	return (false);
}

t_err	t_map_parse_primitive(t_ft_json value, t_map_primitive *out)
{
	if (ft_cstring_equals(ft_json_get_dict(value, "type"), "sphere"))
		return (parse_sphere(value, &out->sphere));
	return (parse_cube(value, &out->cube));
}
