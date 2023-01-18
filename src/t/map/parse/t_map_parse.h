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

#ifndef T_MAP_PARSE_H
# define T_MAP_PARSE_H

# include <stdbool.h>

# include "ft_json_internal.h"
# include "map/t_map.h"

t_map					*t_map_parse(
							t_ft_json_value_internal *value);

t_map_model				*t_map_parse_model(
							t_ft_json_value_internal *value);
t_map_constructive		t_map_parse_constructive(
							t_ft_json_value_internal *value);
t_map_union				t_map_parse_union(
							t_ft_json_value_internal *value);
t_map_intersection		t_map_parse_intersection(
							t_ft_json_value_internal *value);
t_map_difference		t_map_parse_difference(
							t_ft_json_value_internal *value);
t_map_primitive			t_map_parse_primitive(
							t_ft_json_value_internal *value);
t_map_sphere			t_map_parse_sphere(
							t_ft_json_value_internal *value);
t_map_cube				t_map_parse_cube(
							t_ft_json_value_internal *value);
t_map_light				t_map_parse_light(
							t_ft_json_value_internal *value);
t_map_point				t_map_parse_point(
							t_ft_json_value_internal *value);
t_map_directional		t_map_parse_directional(
							t_ft_json_value_internal *value);
t_map_spot				t_map_parse_spot(
							t_ft_json_value_internal *value);
t_map_camera			t_map_parse_camera(
							t_ft_json_value_internal *value);
t_map_viewport			t_map_parse_viewport(
							t_ft_json_value_internal *value);
t_map_position			t_map_parse_position(
							t_ft_json_value_internal *value);
t_map_size3				t_map_parse_size(
							t_ft_json_value_internal *value);
t_map_rotation			t_map_parse_rotation(
							t_ft_json_value_internal *value);
t_map_rotation			t_map_parse_angle(
							t_ft_json_value_internal *value);
t_map_rotation			t_map_parse_normal(
							t_ft_json_value_internal *value);
t_map_light_color		t_map_parse_light_color(
							t_ft_json_value_internal *value);
t_map_material_color	t_map_parse_material_color(
							t_ft_json_value_internal *value);
t_map_map				t_map_parse_map(
							t_ft_json_value_internal *value);
t_map_texture			t_map_parse_texture(
							t_ft_json_value_internal *value);
t_map_material			t_map_parse_material(
							t_ft_json_value_internal *value);

#endif
