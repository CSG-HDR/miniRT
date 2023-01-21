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
void	t_map_free_cube(t_map_cube value);
void	t_map_free_lights(t_map_light *value, size_t count);
void	t_map_free_light(t_map_light value);
void	t_map_free_point(t_map_point value);
void	t_map_free_directional(t_map_directional value);
void	t_map_free_spot(t_map_spot value);
void	t_map_free_camera(t_map_camera value);
void	t_map_free_viewport(t_map_viewport value);
void	t_map_free_position(t_map_position value);
void	t_map_free_size(t_map_size value);
void	t_map_free_rotation(t_map_rotation value);
void	t_map_free_angle(t_map_rotation value);
void	t_map_free_normal(t_map_rotation value);
void	t_map_free_light_color(t_map_light_color value);
void	t_map_free_material_color(t_map_material_color value);
void	t_map_free_color(t_map_color value);
void	t_map_free_normal_map(t_map_normal_map value);
void	t_map_free_texture(t_map_texture value);
void	t_map_free_material(t_map_material value);

#endif
