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

#ifndef T_MAP_FREE_H
# define T_MAP_FREE_H

# include <stddef.h>
# include "t_map.h"

void	t_map_free(t_map *value);

void	t_map_free_models(t_map_model **value, size_t count);
void	t_map_free_model(t_map_model *value);
void	t_map_free_constructive(t_map_constructive value);
void	t_map_free_union(t_map_union value);
void	t_map_free_intersection(t_map_intersection value);
void	t_map_free_difference(t_map_difference value);
void	t_map_free_primitive(t_map_primitive value);
void	t_map_free_sphere(t_map_sphere value);
void	t_map_free_ellipsoid(t_map_ellipsoid value);
void	t_map_free_torus(t_map_torus value);
void	t_map_free_cone(t_map_cone value);
void	t_map_free_cylinder(t_map_cylinder value);
void	t_map_free_cube(t_map_cube value);
void	t_map_free_linear_plane(t_map_linear_plane value);
void	t_map_free_polynomial_plane(t_map_polynomial_plane value);
void	t_map_free_lights(t_map_light *value, size_t count);
void	t_map_free_light(t_map_light value);
void	t_map_free_colors(t_map_color **value, size_t count);
void	t_map_free_color(t_map_color *value);
void	t_map_free_texture(t_map_texture value);
void	t_map_free_blend(t_map_blend value);
void	t_map_free_blend_add(t_map_blend_add value);
void	t_map_free_blend_multiply(t_map_blend_multiply value);
void	t_map_free_blend_maximum(t_map_blend_maximum value);
void	t_map_free_blend_minimum(t_map_blend_minimum value);
void	t_map_free_blend_subtract(t_map_blend_subtract value);
void	t_map_free_normal_map(t_map_normal_map value);
void	t_map_free_material(t_map_material value);

#endif
