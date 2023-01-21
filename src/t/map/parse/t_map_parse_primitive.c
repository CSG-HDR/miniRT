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

t_err	t_map_parse_primitive(t_ft_json value, t_map_primitive *out)
{
	if (t_map_validate_has_type(value, "sphere"))
		return (t_map_parse_primitive_internal_fuck_norm_sphere(
				value, &out->sphere));
	if (t_map_validate_has_type(value, "ellipsoid"))
		return (t_map_parse_primitive_internal_fuck_norm_ellipsoid(
				value, &out->ellipsoid));
	if (t_map_validate_has_type(value, "torus"))
		return (t_map_parse_primitive_internal_fuck_norm_torus(
				value, &out->torus));
	if (t_map_validate_has_type(value, "cone"))
		return (t_map_parse_primitive_internal_fuck_norm_cone(
				value, &out->cone));
	if (t_map_validate_has_type(value, "cylinder"))
		return (t_map_parse_primitive_internal_fuck_norm_cylinder(
				value, &out->cylinder));
	return (t_map_parse_primitive_internal_fuck_norm_cube(
			value, &out->cube));
}
