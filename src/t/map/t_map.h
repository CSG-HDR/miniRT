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

#ifndef T_MAP_H
# define T_MAP_H

# include <stddef.h>
# include <stdbool.h>

# include "t_f.h"
# include "t_f3.h"

// angle in radian
typedef t_f			t_map_angle;
// LDR color
typedef t_f3		t_map_material_color;
// HDR color
typedef t_f3		t_map_light_color;
// normal
typedef t_f3		t_map_normal;
// rotation in radian
typedef t_f3		t_map_rotation;
// 3D size
typedef t_f3		t_map_size;
// position
typedef t_f3		t_map_position;

/////////////////////////////////////////////////////////////////////// material

typedef struct s_map_texture
{
	char		*src;
	t_f			width;
	t_f			height;
	bool		nearest;
	bool		mirror;
}	t_map_texture;

typedef enum e_map_blend_type
{
	T_MAP_BLEND_TYPE_ADD,
	T_MAP_BLEND_TYPE_MULTIPLY,
	T_MAP_BLEND_TYPE_MINIMUM,
	T_MAP_BLEND_TYPE_MAXIMUM,
	T_MAP_BLEND_TYPE_SUBTRACT,
}	t_map_blend_type;

typedef struct s_map_blend_add
{
	t_map_blend_type	type;
	size_t				children_count;
	union u_map_color	**children;
}	t_map_blend_add;

typedef struct s_map_blend_multiply
{
	t_map_blend_type	type;
	size_t				children_count;
	union u_map_color	**children;
}	t_map_blend_multiply;

typedef struct s_map_blend_minimum
{
	t_map_blend_type	type;
	size_t				children_count;
	union u_map_color	**children;
}	t_map_blend_minimum;

typedef struct s_map_blend_maximum
{
	t_map_blend_type	type;
	size_t				children_count;
	union u_map_color	**children;
}	t_map_blend_maximum;

typedef struct s_map_blend_subtract
{
	t_map_blend_type	type;
	union u_map_color	*from;
	union u_map_color	*subtract;
}	t_map_blend_subtract;

typedef union u_map_blend
{
	t_map_blend_type		type;
	t_map_blend_add			add;
	t_map_blend_multiply	multiply;
	t_map_blend_maximum		maximum;
	t_map_blend_minimum		minimum;
	t_map_blend_subtract	subtract;
}	t_map_blend;

typedef enum e_map_color_type
{
	T_MAP_COLOR_TYPE_COLOR,
	T_MAP_COLOR_TYPE_TEXTURE,
	T_MAP_COLOR_TYPE_BLEND,
}	t_map_color_type;

typedef struct s_map_color_color
{
	t_map_color_type		type;
	t_map_material_color	color;
}	t_map_color_color;

typedef struct s_map_color_texture
{
	t_map_color_type	type;
	t_map_texture		texture;
}	t_map_color_texture;

typedef struct s_map_color_blend
{
	t_map_color_type	type;
	t_map_blend			blend;
}	t_map_color_blend;

// designed to be used with its pointer type for avoid type recursion issue
typedef union u_map_color
{
	t_map_color_type	type;
	t_map_color_color	color;
	t_map_color_texture	texture;
	t_map_color_blend	blend;
}	t_map_color;

typedef enum e_map_normal_map_type
{
	T_MAP_NORMAL_MAP_TYPE_NORMAL,
	T_MAP_NORMAL_MAP_TYPE_TEXTURE,
}	t_map_normal_map_type;

typedef struct s_map_normal_map_normal
{
	t_map_normal_map_type	type;
	t_map_normal			normal;
}	t_map_normal_map_normal;

typedef struct s_map_normal_map_texture
{
	t_map_normal_map_type	type;
	t_map_texture			texture;
}	t_map_normal_map_texture;

typedef union u_map_normal_map
{
	t_map_normal_map_type		*type;
	t_map_normal_map_normal		*normal;
	t_map_normal_map_texture	*texture;
}	t_map_normal_map;

typedef struct s_map_material
{
	t_map_color			*ambient;
	t_map_color			*diffuse;
	t_map_color			*specular;
	t_f					specular_lobe;
	bool				has_normal;
	t_map_normal_map	normal;
}	t_map_material;

typedef struct s_map_color_material
{
	t_map_material_color	ambient;
	t_map_material_color	diffuse;
	t_map_material_color	specular;
	t_f						specular_lobe;
}	t_map_color_material;

////////////////////////////////////////////////////////////////////////// light

typedef struct s_map_point
{
	t_map_light_color	color;
	t_map_position		position;
	bool				has_range;
	t_f					range;
}	t_map_point;

typedef struct s_map_directional
{
	t_map_light_color	color;
	t_map_normal		direction;
}	t_map_directional;

typedef struct s_map_spot
{
	t_map_light_color	color;
	t_map_position		position;
	t_map_normal		direction;
	t_map_angle			angle;
	bool				has_range;
	t_f					range;
}	t_map_spot;

typedef enum e_map_light_type
{
	T_MAP_LIGHT_TYPE_POINT,
	T_MAP_LIGHT_TYPE_DIRECTIONAL,
	T_MAP_LIGHT_TYPE_SPOT,
}	t_map_light_type;

typedef struct s_map_light_point
{
	t_map_light_type	type;
	t_map_point			point;
}	t_map_light_point;

typedef struct s_map_light_directional
{
	t_map_light_type	type;
	t_map_directional	directional;
}	t_map_light_directional;

typedef struct s_map_light_spot
{
	t_map_light_type	type;
	t_map_spot			spot;
}	t_map_light_spot;

typedef union u_map_light
{
	t_map_light_type		*type;
	t_map_light_point		*point;
	t_map_light_directional	*directional;
	t_map_light_spot		*spot;
}	t_map_light;

////////////////////////////////////////////////////////////// model - primitive

typedef struct s_map_sphere
{
	t_map_position	position;
	t_f				radius;
	t_map_material	material;
}	t_map_sphere;

typedef struct s_map_ellipsoid
{
	t_map_position	position;
	t_map_size		size;
	t_map_rotation	rotation;
	t_map_material	material;
}	t_map_ellipsoid;

typedef struct s_map_torus
{
	t_map_position	position;
	t_map_size		size;
	t_map_rotation	rotation;
	t_map_material	material;
}	t_map_torus;

typedef struct s_map_cone
{
	t_map_position	position;
	t_map_size		size;
	t_f				offset_x;
	t_f				offset_y;
	t_map_rotation	rotation;
	t_map_material	material_side;
	t_map_material	material_bottom;
}	t_map_cone;

typedef struct s_map_cylinder
{
	t_map_position	position;
	t_map_size		size;
	t_map_rotation	rotation;
	t_map_material	material_side;
	t_map_material	material_top;
	t_map_material	material_bottom;
}	t_map_cylinder;

typedef struct s_map_cube
{
	t_map_position	position;
	t_map_size		size;
	t_map_rotation	rotation;
	t_map_material	material_top;
	t_map_material	material_bottom;
	t_map_material	material_left;
	t_map_material	material_right;
	t_map_material	material_front;
	t_map_material	material_back;
}	t_map_cube;

typedef enum e_map_primitive_type
{
	T_MAP_PRIMITIVE_TYPE_SPHERE,
	T_MAP_PRIMITIVE_TYPE_ELLIPSOID,
	T_MAP_PRIMITIVE_TYPE_TORUS,
	T_MAP_PRIMITIVE_TYPE_CONE,
	T_MAP_PRIMITIVE_TYPE_CYLINDER,
	T_MAP_PRIMITIVE_TYPE_CUBE,
}	t_map_primitive_type;

typedef struct s_map_primitive_sphere
{
	t_map_primitive_type	type;
	t_map_sphere			sphere;
}	t_map_primitive_sphere;

typedef struct s_map_primitive_ellipsoid
{
	t_map_primitive_type	type;
	t_map_ellipsoid			ellipsoid;
}	t_map_primitive_ellipsoid;

typedef struct s_map_primitive_torus
{
	t_map_primitive_type	type;
	t_map_torus				torus;
}	t_map_primitive_torus;

typedef struct s_map_primitive_cone
{
	t_map_primitive_type	type;
	t_map_cone				cone;
}	t_map_primitive_cone;

typedef struct s_map_primitive_cylinder
{
	t_map_primitive_type	type;
	t_map_cylinder			cylinder;
}	t_map_primitive_cylinder;

typedef struct s_map_primitive_cube
{
	t_map_primitive_type	type;
	t_map_cube				cube;
}	t_map_primitive_cube;

typedef union u_map_primitive
{
	t_map_primitive_type		*type;
	t_map_primitive_sphere		*sphere;
	t_map_primitive_ellipsoid	*ellipsoid;
	t_map_primitive_torus		*torus;
	t_map_primitive_cone		*cone;
	t_map_primitive_cylinder	*cylinder;
	t_map_primitive_cube		*cube;
}	t_map_primitive;

/////////////////////////////////////////////////////////// model - constructive

typedef struct s_map_union
{
	size_t				children_count;
	union u_map_model	**children;
}	t_map_union;

typedef struct s_map_intersection
{
	size_t				children_count;
	union u_map_model	**children;
}	t_map_intersection;

typedef struct s_map_difference
{
	union u_map_model	*from;
	union u_map_model	*subtract;
}	t_map_difference;

typedef enum e_map_constructive_type
{
	T_MAP_CONSTRUCTIVE_TYPE_UNION,
	T_MAP_CONSTRUCTIVE_TYPE_INTERSECTION,
	T_MAP_CONSTRUCTIVE_TYPE_DIFFERENCE,
}	t_map_constructive_type;

typedef struct s_map_constructive_union
{
	t_map_constructive_type	type;
	t_map_union				_union;
}	t_map_constructive_union;

typedef struct s_map_constructive_intersection
{
	t_map_constructive_type	type;
	t_map_intersection		intersection;
}	t_map_constructive_intersection;

typedef struct s_map_constructive_difference
{
	t_map_constructive_type	type;
	t_map_difference		difference;
}	t_map_constructive_difference;

typedef union u_map_constructive
{
	t_map_constructive_type			*type;
	t_map_constructive_union		*_union;
	t_map_constructive_intersection	*intersection;
	t_map_constructive_difference	*difference;
}	t_map_constructive;

////////////////////////////////////////////////////////////////////////// model

typedef enum e_map_model_type
{
	T_MAP_MODEL_TYPE_PRIMITIVE,
	T_MAP_MODEL_TYPE_CONSTRUCTIVE,
}	t_map_model_type;

typedef struct s_map_model_primitive
{
	t_map_model_type	type;
	t_map_primitive		primitive;
}	t_map_model_primitive;

typedef struct s_map_model_constructive
{
	t_map_model_type	type;
	t_map_constructive	constructive;
}	t_map_model_constructive;

// designed to be used with its pointer type for avoid type recursion issue
typedef union u_map_model
{
	t_map_model_type			type;
	t_map_model_primitive		primitive;
	t_map_model_constructive	constructive;
}	t_map_model;

//////////////////////////////////////////////////////////////////////////// etc

typedef struct s_map_plane
{
	t_map_position			position;
	t_map_normal			normal;
	t_map_model				*limit;
	t_map_color_material	material;
}	t_map_plane;

typedef struct s_map_quadric
{
	t_f						a;
	t_f						b;
	t_f						c;
	t_f						d;
	t_f						e;
	t_f						f;
	t_f						g;
	t_f						h;
	t_f						i;
	t_f						j;
	t_map_model				*limit;
	t_map_color_material	material;
}	t_map_quadric;

typedef struct s_map_camera
{
	t_map_position	position;
	t_map_rotation	rotation;
	t_map_angle		fov;
}	t_map_camera;

typedef struct s_map_viewport
{
	size_t	width;
	size_t	height;
	size_t	start_x;
	size_t	start_y;
	size_t	end_x;
	size_t	end_y;
}	t_map_viewport;

typedef struct s_map
{
	size_t					model_count;
	t_map_model				**models;
	size_t					light_count;
	t_map_light				*lights;
	size_t					plane_count;
	t_map_plane				*planes;
	size_t					quadric_count;
	t_map_quadric			*quadrics;
	t_map_camera			camera;
	t_map_viewport			viewport;
	t_map_light_color		ambient_light;
	t_map_material_color	void_color;
}	t_map;

#endif
