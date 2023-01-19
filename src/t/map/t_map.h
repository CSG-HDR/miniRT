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

typedef struct s_map_f2
{
	t_f	x;
	t_f	y;
}	t_map_f2;

// LDR color
typedef t_f3		t_map_material_color;
// HDR color
typedef t_f3		t_map_light_color;
// normal
typedef t_f3		t_map_rotation;
// 3D size
typedef t_f3		t_map_size;
// position
typedef t_f3		t_map_position;

typedef struct s_map_texture
{
	char		*src;
	t_f			width;
	t_f			height;
	bool		nearest;
	bool		mirror;
}	t_map_texture;

typedef enum e_map_color_type
{
	T_MAP_COLOR_TYPE_COLOR,
	T_MAP_COLOR_TYPE_TEXTURE,
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

typedef union u_map_color
{
	t_map_color_type	*type;
	t_map_color_color	*color;
	t_map_color_texture	*texture;
}	t_map_color;

typedef enum e_map_map_type
{
	T_MAP_MAP_TYPE_NORMAL,
	T_MAP_MAP_TYPE_TEXTURE,
}	t_map_map_type;

typedef struct s_map_map_normal
{
	t_map_map_type	type;
	t_map_rotation	normal;
}	t_map_map_normal;

typedef struct s_map_map_texture
{
	t_map_map_type	type;
	t_map_texture	texture;
}	t_map_map_texture;

typedef union u_map_map
{
	t_map_map_type		*type;
	t_map_map_normal	*normal;
	t_map_map_texture	*texture;
}	t_map_map;

typedef struct s_map_material
{
	t_map_color	color;
	t_map_map	normal;
}	t_map_material;

////////// light

typedef struct s_map_point
{
	t_map_light_color	color;
	t_map_position		position;
	t_f					range;
}	t_map_point;

typedef struct s_map_directional
{
	t_map_light_color	color;
	t_map_rotation		direction;
}	t_map_directional;

typedef struct s_map_spot
{
	t_map_light_color	color;
	t_map_position		position;
	t_map_rotation		direction;
	t_f					angle;
	t_f					range;
}	t_map_spot;

typedef enum e_map_light_type
{
	T_MAP_LIGHT_POINT,
	T_MAP_LIGHT_DIRECTIONAL,
	T_MAP_LIGHT_SPOT,
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

////////// model - primitive

typedef struct s_map_sphere
{
	t_map_position	position;
	t_f				radius;
	t_map_material	material;
}	t_map_sphere;

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
	T_MAP_PRIMITIVE_SPHERE,
	T_MAP_PRIMITIVE_CUBE,
}	t_map_primitive_type;

typedef struct s_map_primitive_sphere
{
	t_map_primitive_type	type;
	t_map_sphere			sphere;
}	t_map_primitive_sphere;

typedef struct s_map_primitive_cube
{
	t_map_primitive_type	type;
	t_map_cube				cube;
}	t_map_primitive_cube;

typedef union u_map_primitive
{
	t_map_primitive_type	*type;
	t_map_primitive_sphere	*sphere;
	t_map_primitive_cube	*cube;
}	t_map_primitive;

////////// model - constructive

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
	T_MAP_CONSTRUCTIVE_UNION,
	T_MAP_CONSTRUCTIVE_INTERSECTION,
	T_MAP_CONSTRUCTIVE_DIFFERENCE,
}	t_map_constructive_type;

typedef struct s_map_constructive_union
{
	t_map_constructive_type	*type;
	t_map_union				_union;
}	t_map_constructive_union;

typedef struct s_map_constructive_intersection
{
	t_map_constructive_type	*type;
	t_map_intersection		intersection;
}	t_map_constructive_intersection;

typedef struct s_map_constructive_difference
{
	t_map_constructive_type	*type;
	t_map_difference		difference;
}	t_map_constructive_difference;

typedef union u_map_constructive
{
	t_map_constructive_type			*type;
	t_map_constructive_union		*_union;
	t_map_constructive_intersection	*intersection;
	t_map_constructive_difference	*difference;
}	t_map_constructive;

////////// model

typedef enum e_map_model_type
{
	T_MAP_MODEL_PRIMITIVE,
	T_MAP_MODEL_CONSTRUCTIVE,
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

typedef union u_map_model
{
	t_map_model_type			type;
	t_map_model_primitive		primitive;
	t_map_model_constructive	constructive;
}	t_map_model;

////////// etc

typedef struct s_map_camera
{
	t_map_position	position;
	t_map_rotation	rotation;
	t_f				fov;
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
	t_map_model				*models;
	size_t					light_count;
	t_map_light				*lights;
	t_map_camera			camera;
	t_map_viewport			viewport;
	t_map_light_color		ambient_light;
	t_map_material_color	void_color;
}	t_map;

#endif
