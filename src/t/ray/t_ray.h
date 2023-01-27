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

#ifndef T_RAY_H
# define T_RAY_H

# include <stdbool.h>

# include "ft_types.h"
# include "t_f.h"
# include "t_f3.h"
# include "t_map.h"

typedef struct s_ray
{
	t_map_position	origin;
	t_map_normal	direction;
}	t_ray;

typedef enum e_ray_material_type
{
	T_RAY_MATERIAL_TYPE_COLOR,
	T_RAY_MATERIAL_TYPE_COMPUTED,
}	t_ray_material_type;

typedef struct s_ray_material_color
{
	t_ray_material_type	type;
	t_map_color			*color;
}	t_ray_material_color;

typedef struct s_ray_material_computed
{
	t_ray_material_type		type;
	t_map_color_material	computed;
}	t_ray_material_computed;

typedef union s_ray_material
{
	t_ray_material_type		type;
	t_ray_material_color	color;
	t_ray_material_computed	computed;
}	t_ray_material;

typedef struct s_ray_hit_record
{
	t_map_position	position;
	t_map_normal	normal;
	t_ray_material	material;
	bool			is_front_face;
}	t_ray_hit_record;

typedef struct s_ray_hit_records
{
	size_t				hit_record_count;
	t_ray_hit_record	hit_records;
}	t_ray_hit_records;

/**
 * @brief get ray for x, y in [0, 0] to [1, 1]
 */
t_ray	t_ray_get(t_map *map, t_f x, t_f y);

void	t_ray_hit_records_free(t_ray_hit_records records);
t_err	t_ray_union(
			size_t count, t_ray_hit_records rays, t_ray_hit_records *out);
t_err	t_ray_intersection(
			size_t count, t_ray_hit_records rays, t_ray_hit_records *out);
t_err	t_ray_difference(
			t_ray_hit_records from,
			t_ray_hit_records subtract,
			t_ray_hit_records *out);
t_err	t_ray_model(t_ray ray, t_map_model *model, t_ray_hit_records *out);

t_err	t_ray_constructive(
			t_ray ray, t_map_constructive constructive, t_ray_hit_records *out);
t_err	t_ray_csg_union(t_ray ray, t_map_union _union, t_ray_hit_records *out);
t_err	t_ray_csg_intersection(
			t_ray ray, t_map_intersection intersection, t_ray_hit_records *out);
t_err	t_ray_csg_difference(
			t_ray ray, t_map_difference difference, t_ray_hit_records *out);
t_err	t_ray_primitive(
			t_ray ray, t_map_primitive primitive, t_ray_hit_records *out);
t_err	t_ray_sphere(t_ray ray, t_map_sphere sphere, t_ray_hit_records *out);
t_err	t_ray_ellipsoid(
			t_ray ray, t_map_ellipsoid ellipsoid, t_ray_hit_records *out);
t_err	t_ray_torus(t_ray ray, t_map_torus torus, t_ray_hit_records *out);
t_err	t_ray_cone(t_ray ray, t_map_cone cone, t_ray_hit_records *out);
t_err	t_ray_cylinder(
			t_ray ray, t_map_cylinder cylinder, t_ray_hit_records *out);
t_err	t_ray_cube(t_ray ray, t_map_cube cube, t_ray_hit_records *out);
t_err	t_ray_plane(
			t_ray ray, t_map_plane plane, t_ray_hit_records *out);
t_err	t_ray_quadric(
			t_ray ray, t_map_quadric quadric, t_ray_hit_records *out);

#endif
