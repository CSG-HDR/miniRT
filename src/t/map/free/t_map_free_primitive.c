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

#include "t_map_free.h"

#include "wrap.h"
#include "t_map.h"

static void	circle_related(t_map_primitive value)
{
	if (*value.type == T_MAP_PRIMITIVE_TYPE_SPHERE)
	{
		t_map_free_sphere(value.sphere->sphere);
		wrap_free(value.sphere);
	}
	if (*value.type == T_MAP_PRIMITIVE_TYPE_ELLIPSOID)
	{
		t_map_free_ellipsoid(value.ellipsoid->ellipsoid);
		wrap_free(value.ellipsoid);
	}
	if (*value.type == T_MAP_PRIMITIVE_TYPE_CONE)
	{
		t_map_free_cone(value.cone->cone);
		wrap_free(value.cone);
	}
	if (*value.type == T_MAP_PRIMITIVE_TYPE_CYLINDER)
	{
		t_map_free_cylinder(value.cylinder->cylinder);
		wrap_free(value.cylinder);
	}
}

void	t_map_free_primitive(t_map_primitive value)
{
	circle_related(value);
	if (*value.type == T_MAP_PRIMITIVE_TYPE_CUBE)
	{
		t_map_free_cube(value.cube->cube);
		wrap_free(value.cube);
	}
}
