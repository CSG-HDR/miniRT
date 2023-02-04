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

#include "t_texture_manager.h"

#include "t_map.h"

t_err	t_texture_manager_preload_primitive(
	t_texture_manager *self,
	t_map_primitive primitive
)
{
	if (*primitive.type == T_MAP_PRIMITIVE_TYPE_SPHERE)
		return (t_texture_manager_preload_sphere(
				self, primitive.sphere->sphere));
	if (*primitive.type == T_MAP_PRIMITIVE_TYPE_ELLIPSOID)
		return (t_texture_manager_preload_ellipsoid(
				self, primitive.ellipsoid->ellipsoid));
	if (*primitive.type == T_MAP_PRIMITIVE_TYPE_CONE)
		return (t_texture_manager_preload_cone(
				self, primitive.cone->cone));
	if (*primitive.type == T_MAP_PRIMITIVE_TYPE_CYLINDER)
		return (t_texture_manager_preload_cylinder(
				self, primitive.cylinder->cylinder));
	else
		return (t_texture_manager_preload_cube(
				self, primitive.cube->cube));
}
