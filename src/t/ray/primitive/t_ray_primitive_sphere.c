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

t_err	t_ray_primitive_sphere(
	t_ray ray,
	t_map_sphere sphere,
	t_ray_hit_records *out
)
{
	const t_map_ellipsoid	as_ellipsoid = {
		sphere.position,
		(t_map_size){sphere.radius, sphere.radius, sphere.radius},
		(t_map_rotation){0, 0, 0},
		sphere.material,
	};

	return (t_ray_primitive_ellipsoid(ray, as_ellipsoid, out));
}
