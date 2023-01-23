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

# include "ft_json.h"

bool	t_map_validate(t_ft_json value);

bool	t_map_validate_models(t_ft_json value);
bool	t_map_validate_model(t_ft_json value);
bool	t_map_validate_constructive(t_ft_json value);
bool	t_map_validate_union(t_ft_json value);
bool	t_map_validate_intersection(t_ft_json value);
bool	t_map_validate_difference(t_ft_json value);
bool	t_map_validate_primitive(t_ft_json value);
bool	t_map_validate_sphere(t_ft_json value);
bool	t_map_validate_ellipsoid(t_ft_json value);
bool	t_map_validate_torus(t_ft_json value);
bool	t_map_validate_cone(t_ft_json value);
bool	t_map_validate_cylinder(t_ft_json value);
bool	t_map_validate_cube(t_ft_json value);
bool	t_map_validate_linear_plane(t_ft_json value);
bool	t_map_validate_polynomial_plane(t_ft_json value);
bool	t_map_validate_light(t_ft_json value);
bool	t_map_validate_point(t_ft_json value);
bool	t_map_validate_directional(t_ft_json value);
bool	t_map_validate_spot(t_ft_json value);
bool	t_map_validate_camera(t_ft_json value);
bool	t_map_validate_viewport(t_ft_json value);
bool	t_map_validate_position(t_ft_json value);
bool	t_map_validate_size(t_ft_json value);
bool	t_map_validate_rotation(t_ft_json value);
bool	t_map_validate_normal(t_ft_json value);
bool	t_map_validate_light_color(t_ft_json value);
bool	t_map_validate_material_color(t_ft_json value);
bool	t_map_validate_color_material(t_ft_json value);
bool	t_map_validate_colors(t_ft_json value);
bool	t_map_validate_color(t_ft_json value);
bool	t_map_validate_texture(t_ft_json value);
bool	t_map_validate_blend(t_ft_json value);
bool	t_map_validate_blend_add(t_ft_json value);
bool	t_map_validate_blend_multiply(t_ft_json value);
bool	t_map_validate_blend_maximum(t_ft_json value);
bool	t_map_validate_blend_minimum(t_ft_json value);
bool	t_map_validate_blend_subtract(t_ft_json value);
bool	t_map_validate_normal_map(t_ft_json value);
bool	t_map_validate_material(t_ft_json value);

bool	t_map_validate_has_type(t_ft_json value, const char *type);
bool	t_map_validate_has_number_list(t_ft_json value, size_t index);
bool	t_map_validate_has_number_dict(t_ft_json value, const char *key);
bool	t_map_validate_has_position(t_ft_json value);
bool	t_map_validate_has_size(t_ft_json value);
bool	t_map_validate_has_rotation(t_ft_json value);
bool	t_map_validate_has_direction(t_ft_json value);
bool	t_map_validate_has_color(t_ft_json value);
bool	t_map_validate_has_optional_number(t_ft_json value, const char *key);
bool	t_map_validate_has_optional_range(t_ft_json value);
bool	t_map_validate_has_optional_material(t_ft_json value);
bool	t_map_validate_has_optional_specular_lobe(t_ft_json value);

#endif
