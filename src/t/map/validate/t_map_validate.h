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

#ifndef T_MAP_VALIDATE_H
# define T_MAP_VALIDATE_H

# include <stdbool.h>

# include "ft_json_internal.h"

bool	t_map_validate(t_ft_json_value_internal *value);

bool	t_map_validate_model(
			t_ft_json_value_internal *value);
bool	t_map_validate_constructive(
			t_ft_json_value_internal *value);
bool	t_map_validate_union(
			t_ft_json_value_internal *value);
bool	t_map_validate_intersection(
			t_ft_json_value_internal *value);
bool	t_map_validate_difference(
			t_ft_json_value_internal *value);
bool	t_map_validate_primitive(
			t_ft_json_value_internal *value);
bool	t_map_validate_sphere(
			t_ft_json_value_internal *value);
bool	t_map_validate_cube(
			t_ft_json_value_internal *value);
bool	t_map_validate_light(
			t_ft_json_value_internal *value);
bool	t_map_validate_point(
			t_ft_json_value_internal *value);
bool	t_map_validate_directional(
			t_ft_json_value_internal *value);
bool	t_map_validate_spot(
			t_ft_json_value_internal *value);
bool	t_map_validate_camera(
			t_ft_json_value_internal *value);
bool	t_map_validate_viewport(
			t_ft_json_value_internal *value);
bool	t_map_validate_position(
			t_ft_json_value_internal *value);
bool	t_map_validate_size(
			t_ft_json_value_internal *value);
bool	t_map_validate_rotation(
			t_ft_json_value_internal *value);
bool	t_map_validate_angle(
			t_ft_json_value_internal *value);
bool	t_map_validate_normal(
			t_ft_json_value_internal *value);
bool	t_map_validate_light_color(
			t_ft_json_value_internal *value);
bool	t_map_validate_material_color(
			t_ft_json_value_internal *value);
bool	t_map_validate_map(
			t_ft_json_value_internal *value);
bool	t_map_validate_texture(
			t_ft_json_value_internal *value);
bool	t_map_validate_material(
			t_ft_json_value_internal *value);

#endif
