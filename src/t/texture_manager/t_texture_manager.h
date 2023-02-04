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

#ifndef T_TEXTURE_MANAGER_H
# define T_TEXTURE_MANAGER_H

# include <stddef.h>

# include "t_image.h"
# include "t_map.h"

// TODO: use balanced BST or HashTable based data structure

typedef struct s_texture_manager_node
{
	struct s_texture_manager_node	*next;
	char							*path;
	t_image							*image;
}	t_texture_manager_node;

typedef struct s_texture_manager
{
	t_texture_manager_node	*head;
	t_texture_manager_node	*tail;
}	t_texture_manager;

t_texture_manager	*t_texture_manager_new(void);
void				t_texture_manager_free(
						t_texture_manager *self);
t_err				t_texture_manager_preload(
						t_texture_manager *self,
						const char *path);
const t_image		*t_texture_manager_get(
						t_texture_manager *self,
						const char *path);

t_err				t_texture_manager_preload_all(
						t_texture_manager *self,
						t_map *map);
t_err				t_texture_manager_preload_models(
						t_texture_manager *self,
						t_map_model **models,
						size_t count);
t_err				t_texture_manager_preload_model(
						t_texture_manager *self,
						t_map_model *model);
t_err				t_texture_manager_preload_constructive(
						t_texture_manager *self,
						t_map_constructive constructive);
t_err				t_texture_manager_preload_union(
						t_texture_manager *self,
						t_map_union _union);
t_err				t_texture_manager_preload_intersection(
						t_texture_manager *self,
						t_map_intersection intersection);
t_err				t_texture_manager_preload_difference(
						t_texture_manager *self,
						t_map_difference difference);
t_err				t_texture_manager_preload_primitive(
						t_texture_manager *self,
						t_map_primitive primitive);
t_err				t_texture_manager_preload_sphere(
						t_texture_manager *self,
						t_map_sphere sphere);
t_err				t_texture_manager_preload_ellipsoid(
						t_texture_manager *self,
						t_map_ellipsoid ellipsoid);
t_err				t_texture_manager_preload_cone(
						t_texture_manager *self,
						t_map_cone cone);
t_err				t_texture_manager_preload_cylinder(
						t_texture_manager *self,
						t_map_cylinder cylinder);
t_err				t_texture_manager_preload_cube(
						t_texture_manager *self,
						t_map_cube cube);
t_err				t_texture_manager_preload_material(
						t_texture_manager *self,
						t_map_material material);
t_err				t_texture_manager_preload_normal_map(
						t_texture_manager *self,
						t_map_normal_map normal_map);
t_err				t_texture_manager_preload_colors(
						t_texture_manager *self,
						t_map_color **color,
						size_t count);
t_err				t_texture_manager_preload_color(
						t_texture_manager *self,
						t_map_color *color);
t_err				t_texture_manager_preload_texture(
						t_texture_manager *self,
						t_map_texture texture);
t_err				t_texture_manager_preload_blend(
						t_texture_manager *self,
						t_map_blend blend);
t_err				t_texture_manager_preload_blend_add(
						t_texture_manager *self,
						t_map_blend_add blend_add);
t_err				t_texture_manager_preload_blend_multiply(
						t_texture_manager *self,
						t_map_blend_multiply blend_multiply);
t_err				t_texture_manager_preload_blend_maximum(
						t_texture_manager *self,
						t_map_blend_maximum blend_maximum);
t_err				t_texture_manager_preload_blend_minimum(
						t_texture_manager *self,
						t_map_blend_minimum blend_minimum);
t_err				t_texture_manager_preload_blend_subtract(
						t_texture_manager *self,
						t_map_blend_subtract blend_subtract);

#endif
