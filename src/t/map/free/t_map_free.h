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
void	t_map_free_cube(t_map_cube value);
void	t_map_free_lights(t_map_light *value, size_t count);
void	t_map_free_light(t_map_light value);
void	t_map_free_planes(t_map_plane *value, size_t count);
void	t_map_free_plane(t_map_plane value);
void	t_map_free_color(t_map_color value);
void	t_map_free_normal_map(t_map_normal_map value);
void	t_map_free_texture(t_map_texture value);
void	t_map_free_material(t_map_material value);

#endif
