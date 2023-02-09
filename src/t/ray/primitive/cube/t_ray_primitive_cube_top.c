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

#include "t_ray_primitive_cube.h"

#include "ft_types.h"
#include "t_map.h"
#include "t_ray.h"

typedef struct s_locals
{
	t_f				distance;
	t_map_position	point;
	t_f				x;
	t_f				y;
	bool			is_front_face;
}	t_locals;

t_err	t_ray_primitive_cube_top(
	t_ray ray,
	t_map_cube cube,
	t_ray_hit_records_builder *builder
)
{
	t_locals			l;
	const t_map_normal	normal = {(t_f)0, (t_f)0, (t_f)1};

	l.distance = -(ray.origin.z - cube.size.z) / ray.direction.z;
	if (l.distance < 0)
		return (false);
	l.point = t_f3_add(ray.origin, t_f3_mul(ray.direction, l.distance));
	l.x = l.point.x / cube.size.x;
	l.y = l.point.y / cube.size.y;
	if (l.x < 0 || l.y < 0 || l.x > 1 || l.y > 1)
		return (false);
	l.is_front_face = ray.direction.z < 0;
	return (t_ray_hit_records_builder_add(builder, (t_ray_hit_record){
		l.distance,
		normal,
		t_ray_material_from_color(cube.material_top),
		l.is_front_face,
		l.x,
		l.y
		})
	);
}
