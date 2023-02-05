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

#include "t_ray_primitive_cone.h"

#include <stdbool.h>

#include "ft_types.h"
#include "t_f3.h"
#include "t_map.h"
#include "t_ray.h"

typedef struct s_locals
{
	t_f				distance;
	t_map_position	point;
	t_f				x;
	t_f				y;
	t_f				sqr_eccentricity;
	t_map_normal	normal;
	bool			is_front_face;
}	t_locals;

t_err	t_ray_primitive_cone_bottom(
	t_ray ray,
	t_map_cone cone,
	t_ray_hit_records_builder *builder
)
{
	t_locals	l;

	l.distance = -ray.origin.z / ray.direction.z;
	l.point = t_f3_add(ray.origin, t_f3_mul(ray.direction, l.distance));
	l.x = l.point.x / cone.size.x;
	l.y = l.point.y / cone.size.y;
	l.sqr_eccentricity = (l.x * l.x) + (l.y * l.y);
	if (l.distance < 0 || l.sqr_eccentricity > 1)
		return (false);
	l.is_front_face = ray.direction.z > 0;
	if (l.is_front_face)
		l.normal = (t_map_normal){0, 0, -1};
	else
		l.normal = (t_map_normal){0, 0, 1};
	return (t_ray_hit_records_builder_add(builder, (t_ray_hit_record){
			l.distance,
			l.normal,
			t_ray_material_from_color(cone.material_bottom),
			l.is_front_face,
			l.x,
			l.y
		})
	);
}
