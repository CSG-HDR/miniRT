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
	t_map_material		color;
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
	t_f				distance;
	t_map_normal	normal;
	t_ray_material	material;
	bool			is_front_face;
	t_f				x;
	t_f				y;
}	t_ray_hit_record;

typedef struct s_ray_hit_records
{
	size_t				hit_record_count;
	t_ray_hit_record	*hit_records;
}	t_ray_hit_records;

typedef struct s_ray_hit_records_builder_node
{
	struct s_ray_hit_records_builder_node	*next;
	t_ray_hit_record						record;
}	t_ray_hit_records_builder_node;

typedef struct s_ray_hit_records_builder
{
	t_ray_hit_records_builder_node	*head;
	t_ray_hit_records_builder_node	*tail;
	size_t							count;
}	t_ray_hit_records_builder;

typedef struct s_ray_nearest_quartic_vars
{
	t_f	p;
	t_f	q;
	t_f	r;
	t_f	u;
	t_f	v;
	t_f	w;
}	t_ray_nearest_quartic_vars;

typedef struct s_ray_nearest_quartic_equation
{
	t_f	a;
	t_f	b;
	t_f	c;
	t_f	d;
	t_f	e;
}	t_ray_nearest_quartic_equation;

t_ray_material		t_ray_material_from_computed(t_map_color_material material);
t_ray_material		t_ray_material_from_color(t_map_material material);
t_ray_hit_record	t_ray_default_hit_record(t_map_material material);

t_err				t_ray_hit_records_builder_init(
						t_ray_hit_records_builder **out);
t_err				t_ray_hit_records_builder_build(
						t_ray_hit_records_builder *self,
						t_ray_hit_records *out);
t_err				t_ray_hit_records_builder_add(
						t_ray_hit_records_builder *self,
						t_ray_hit_record record);
void				t_ray_hit_records_builder_free(
						t_ray_hit_records_builder *self);

/**
 * @brief get ray for x, y in [0, 0] to [1, 1]
 */
t_ray				t_ray_get(t_map *map, t_f x, t_f y);

t_ray				t_ray_preprocess(
						t_ray ray,
						t_map_position position,
						t_map_rotation rotation);
void				t_ray_hit_records_free(
						t_ray_hit_records records);
t_err				t_ray_hit_records_copy(
						t_ray_hit_records src,
						t_ray_hit_records *dest);
t_err				t_ray_hit_records_copy_first(
						t_ray_hit_records src,
						t_ray_hit_records *dest);
t_err				t_ray_nearest(
						t_ray_hit_records a,
						t_ray_hit_records b,
						t_ray_hit_records *out);
t_err				t_ray_nearest_map(
						t_ray ray,
						t_map *map,
						t_ray_hit_records *out);
t_err				t_ray_nearest_model(
						t_ray ray,
						t_map_model *model,
						t_ray_hit_records *out);
t_err				t_ray_nearest_models(
						t_ray ray,
						t_map_model **models,
						size_t model_count,
						t_ray_hit_records *out);
t_err				t_ray_nearest_plane(
						t_ray ray,
						t_map_plane plane,
						t_ray_hit_records *out);
t_err				t_ray_nearest_planes(
						t_ray ray,
						t_map_plane *planes,
						size_t plane_count,
						t_ray_hit_records *out);
t_err				t_ray_nearest_quadric(
						t_ray ray,
						t_map_quadric quadric,
						t_ray_hit_records *out);
t_err				t_ray_nearest_quadrics(
						t_ray ray,
						t_map_quadric *quadrics,
						size_t quadric_count,
						t_ray_hit_records *out);
t_err				t_ray_nearest_quartic(
						t_ray ray,
						t_map_quartic quartic,
						t_ray_hit_records *out);
void				t_ray_nearest_quartic_c400(
						t_ray_nearest_quartic_vars v,
						t_map_quartic q,
						t_ray_nearest_quartic_equation *mut_result);
void				t_ray_nearest_quartic_c040(
						t_ray_nearest_quartic_vars v,
						t_map_quartic q,
						t_ray_nearest_quartic_equation *mut_result);
void				t_ray_nearest_quartic_c004(
						t_ray_nearest_quartic_vars v,
						t_map_quartic q,
						t_ray_nearest_quartic_equation *mut_result);
void				t_ray_nearest_quartic_c310(
						t_ray_nearest_quartic_vars v,
						t_map_quartic q,
						t_ray_nearest_quartic_equation *mut_result);
void				t_ray_nearest_quartic_c301(
						t_ray_nearest_quartic_vars v,
						t_map_quartic q,
						t_ray_nearest_quartic_equation *mut_result);
void				t_ray_nearest_quartic_c130(
						t_ray_nearest_quartic_vars v,
						t_map_quartic q,
						t_ray_nearest_quartic_equation *mut_result);
void				t_ray_nearest_quartic_c031(
						t_ray_nearest_quartic_vars v,
						t_map_quartic q,
						t_ray_nearest_quartic_equation *mut_result);
void				t_ray_nearest_quartic_c103(
						t_ray_nearest_quartic_vars v,
						t_map_quartic q,
						t_ray_nearest_quartic_equation *mut_result);
void				t_ray_nearest_quartic_c013(
						t_ray_nearest_quartic_vars v,
						t_map_quartic q,
						t_ray_nearest_quartic_equation *mut_result);
void				t_ray_nearest_quartic_c220(
						t_ray_nearest_quartic_vars v,
						t_map_quartic q,
						t_ray_nearest_quartic_equation *mut_result);
void				t_ray_nearest_quartic_c022(
						t_ray_nearest_quartic_vars v,
						t_map_quartic q,
						t_ray_nearest_quartic_equation *mut_result);
void				t_ray_nearest_quartic_c202(
						t_ray_nearest_quartic_vars v,
						t_map_quartic q,
						t_ray_nearest_quartic_equation *mut_result);
void				t_ray_nearest_quartic_c211(
						t_ray_nearest_quartic_vars v,
						t_map_quartic q,
						t_ray_nearest_quartic_equation *mut_result);
void				t_ray_nearest_quartic_c121(
						t_ray_nearest_quartic_vars v,
						t_map_quartic q,
						t_ray_nearest_quartic_equation *mut_result);
void				t_ray_nearest_quartic_c112(
						t_ray_nearest_quartic_vars v,
						t_map_quartic q,
						t_ray_nearest_quartic_equation *mut_result);
void				t_ray_nearest_quartic_c300(
						t_ray_nearest_quartic_vars v,
						t_map_quartic q,
						t_ray_nearest_quartic_equation *mut_result);
void				t_ray_nearest_quartic_c030(
						t_ray_nearest_quartic_vars v,
						t_map_quartic q,
						t_ray_nearest_quartic_equation *mut_result);
void				t_ray_nearest_quartic_c003(
						t_ray_nearest_quartic_vars v,
						t_map_quartic q,
						t_ray_nearest_quartic_equation *mut_result);
void				t_ray_nearest_quartic_c210(
						t_ray_nearest_quartic_vars v,
						t_map_quartic q,
						t_ray_nearest_quartic_equation *mut_result);
void				t_ray_nearest_quartic_c201(
						t_ray_nearest_quartic_vars v,
						t_map_quartic q,
						t_ray_nearest_quartic_equation *mut_result);
void				t_ray_nearest_quartic_c120(
						t_ray_nearest_quartic_vars v,
						t_map_quartic q,
						t_ray_nearest_quartic_equation *mut_result);
void				t_ray_nearest_quartic_c021(
						t_ray_nearest_quartic_vars v,
						t_map_quartic q,
						t_ray_nearest_quartic_equation *mut_result);
void				t_ray_nearest_quartic_c102(
						t_ray_nearest_quartic_vars v,
						t_map_quartic q,
						t_ray_nearest_quartic_equation *mut_result);
void				t_ray_nearest_quartic_c012(
						t_ray_nearest_quartic_vars v,
						t_map_quartic q,
						t_ray_nearest_quartic_equation *mut_result);
void				t_ray_nearest_quartic_c111(
						t_ray_nearest_quartic_vars v,
						t_map_quartic q,
						t_ray_nearest_quartic_equation *mut_result);
void				t_ray_nearest_quartic_c200(
						t_ray_nearest_quartic_vars v,
						t_map_quartic q,
						t_ray_nearest_quartic_equation *mut_result);
void				t_ray_nearest_quartic_c020(
						t_ray_nearest_quartic_vars v,
						t_map_quartic q,
						t_ray_nearest_quartic_equation *mut_result);
void				t_ray_nearest_quartic_c002(
						t_ray_nearest_quartic_vars v,
						t_map_quartic q,
						t_ray_nearest_quartic_equation *mut_result);
void				t_ray_nearest_quartic_c110(
						t_ray_nearest_quartic_vars v,
						t_map_quartic q,
						t_ray_nearest_quartic_equation *mut_result);
void				t_ray_nearest_quartic_c011(
						t_ray_nearest_quartic_vars v,
						t_map_quartic q,
						t_ray_nearest_quartic_equation *mut_result);
void				t_ray_nearest_quartic_c101(
						t_ray_nearest_quartic_vars v,
						t_map_quartic q,
						t_ray_nearest_quartic_equation *mut_result);
void				t_ray_nearest_quartic_c100(
						t_ray_nearest_quartic_vars v,
						t_map_quartic q,
						t_ray_nearest_quartic_equation *mut_result);
void				t_ray_nearest_quartic_c010(
						t_ray_nearest_quartic_vars v,
						t_map_quartic q,
						t_ray_nearest_quartic_equation *mut_result);
void				t_ray_nearest_quartic_c001(
						t_ray_nearest_quartic_vars v,
						t_map_quartic q,
						t_ray_nearest_quartic_equation *mut_result);
void				t_ray_nearest_quartic_c000(
						t_ray_nearest_quartic_vars v,
						t_map_quartic q,
						t_ray_nearest_quartic_equation *mut_result);
t_err				t_ray_nearest_quartics(
						t_ray ray,
						t_map_quartic *quartics,
						size_t quartic_count,
						t_ray_hit_records *out);
t_err				t_ray_merge(
						const t_ray_hit_records *rays,
						size_t count,
						t_ray_hit_records *out);
t_err				t_ray_union(
						const t_ray_hit_records *rays,
						size_t count,
						t_ray_hit_records *out);
t_err				t_ray_intersection(
						const t_ray_hit_records *rays,
						size_t count,
						t_ray_hit_records *out);
t_err				t_ray_difference(
						t_ray_hit_records from,
						t_ray_hit_records subtract,
						t_ray_hit_records *out);
t_err				t_ray_model(
						t_ray ray,
						t_map_model *model,
						t_ray_hit_records *out);
t_err				t_ray_constructive(
						t_ray ray,
						t_map_constructive constructive,
						t_ray_hit_records *out);
t_err				t_ray_constructive_union(
						t_ray ray,
						t_map_union _union,
						t_ray_hit_records *out);
t_err				t_ray_constructive_intersection(
						t_ray ray,
						t_map_intersection intersection,
						t_ray_hit_records *out);
t_err				t_ray_constructive_difference(
						t_ray ray,
						t_map_difference difference,
						t_ray_hit_records *out);
t_err				t_ray_primitive(
						t_ray ray,
						t_map_primitive primitive,
						t_ray_hit_records *out);
t_err				t_ray_primitive_sphere(
						t_ray ray,
						t_map_sphere sphere,
						t_ray_hit_records *out);
t_err				t_ray_primitive_ellipsoid(
						t_ray ray,
						t_map_ellipsoid ellipsoid,
						t_ray_hit_records *out);
t_err				t_ray_primitive_cone(
						t_ray ray,
						t_map_cone cone,
						t_ray_hit_records *out);
t_err				t_ray_primitive_cylinder(
						t_ray ray,
						t_map_cylinder cylinder,
						t_ray_hit_records *out);
t_err				t_ray_primitive_cube(
						t_ray ray,
						t_map_cube cube,
						t_ray_hit_records *out);

#endif
