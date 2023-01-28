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

#include "t_ray.h"

#include "ft_types.h"
#include "t_map.h"

t_err	t_ray_primitive(
	t_ray ray,
	t_map_primitive primitive,
	t_ray_hit_records *out
)
{
	if (*primitive.type == T_MAP_PRIMITIVE_TYPE_SPHERE)
		return (t_ray_primitive_sphere(
				ray, primitive.sphere->sphere, out));
	if (*primitive.type == T_MAP_PRIMITIVE_TYPE_ELLIPSOID)
		return (t_ray_primitive_ellipsoid(
				ray, primitive.ellipsoid->ellipsoid, out));
	if (*primitive.type == T_MAP_PRIMITIVE_TYPE_TORUS)
		return (t_ray_primitive_torus(
				ray, primitive.torus->torus, out));
	if (*primitive.type == T_MAP_PRIMITIVE_TYPE_CONE)
		return (t_ray_primitive_cone(
				ray, primitive.cone->cone, out));
	if (*primitive.type == T_MAP_PRIMITIVE_TYPE_CYLINDER)
		return (t_ray_primitive_cylinder(
				ray, primitive.cylinder->cylinder, out));
	else
		return (t_ray_primitive_cube(
				ray, primitive.cube->cube, out));
}
