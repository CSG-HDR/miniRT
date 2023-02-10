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

# include "ft_json.h"
# include "t_f.h"
# include "t_map.h"

t_err	t_map_parse(t_ft_json value, t_map **out);

t_err	t_map_parse_models(
			t_ft_json value, t_map_model ***out, size_t *out_count);
t_err	t_map_parse_model(t_ft_json value, t_map_model **out);
t_err	t_map_parse_constructive(t_ft_json value, t_map_constructive *out);
t_err	t_map_parse_union(t_ft_json value, t_map_union *out);
t_err	t_map_parse_intersection(t_ft_json value, t_map_intersection *out);
t_err	t_map_parse_difference(t_ft_json value, t_map_difference *out);
t_err	t_map_parse_primitive(t_ft_json value, t_map_primitive *out);
t_err	t_map_parse_primitive_internal_fuck_norm_sphere(
			t_ft_json value, t_map_primitive_sphere **out);
t_err	t_map_parse_primitive_internal_fuck_norm_ellipsoid(
			t_ft_json value, t_map_primitive_ellipsoid **out);
t_err	t_map_parse_primitive_internal_fuck_norm_cone(
			t_ft_json value, t_map_primitive_cone **out);
t_err	t_map_parse_primitive_internal_fuck_norm_cylinder(
			t_ft_json value, t_map_primitive_cylinder **out);
t_err	t_map_parse_primitive_internal_fuck_norm_cube(
			t_ft_json value, t_map_primitive_cube **out);
t_err	t_map_parse_sphere(t_ft_json value, t_map_sphere *out);
t_err	t_map_parse_ellipsoid(t_ft_json value, t_map_ellipsoid *out);
t_err	t_map_parse_cone(t_ft_json value, t_map_cone *out);
t_err	t_map_parse_cylinder(t_ft_json value, t_map_cylinder *out);
t_err	t_map_parse_cube(t_ft_json value, t_map_cube *out);
t_err	t_map_parse_cube_internal_by_fucking_norm(t_map_cube *out);
t_err	t_map_parse_lights(
			t_ft_json value, t_map_light **out, size_t *out_count);
t_err	t_map_parse_light(t_ft_json value, t_map_light *out);
t_err	t_map_parse_planes(
			t_ft_json value, t_map_plane **out, size_t *out_count);
void	t_map_parse_plane(t_ft_json value, t_map_plane *out);
t_err	t_map_parse_quadrics(
			t_ft_json value, t_map_quadric **out, size_t *out_count);
void	t_map_parse_quadric(t_ft_json value, t_map_quadric *out);
void	t_map_parse_point(t_ft_json value, t_map_point *out);
void	t_map_parse_directional(t_ft_json value, t_map_directional *out);
void	t_map_parse_spot(t_ft_json value, t_map_spot *out);
void	t_map_parse_camera(
			t_ft_json value, t_map_camera *out, t_map_viewport *viewport);
void	t_map_parse_camera_rotation(t_ft_json value, t_map_camera *out);
void	t_map_parse_viewport(t_ft_json value, t_map_viewport *out);
void	t_map_parse_position(t_ft_json value, t_map_position *out);
void	t_map_parse_size(t_ft_json value, t_map_size *out);
void	t_map_parse_rotation(t_ft_json value, t_map_rotation *out);
void	t_map_parse_normal(t_ft_json value, t_map_normal *out);
void	t_map_parse_light_color(t_ft_json value, t_map_light_color *out);
void	t_map_parse_material_color(t_ft_json value, t_map_material_color *out);
void	t_map_parse_color_material(t_ft_json value, t_map_color_material *out);
t_err	t_map_parse_colors(
			t_ft_json value, t_map_color ***out, size_t *out_count);
t_err	t_map_parse_color(t_ft_json value, t_map_color **out);
t_err	t_map_parse_texture(t_ft_json value, t_map_texture *out);
t_err	t_map_parse_blend(t_ft_json value, t_map_blend *out);
t_err	t_map_parse_blend_add(t_ft_json value, t_map_blend_add *out);
t_err	t_map_parse_blend_multiply(t_ft_json value, t_map_blend_multiply *out);
t_err	t_map_parse_blend_maximum(t_ft_json value, t_map_blend_maximum *out);
t_err	t_map_parse_blend_minimum(t_ft_json value, t_map_blend_minimum *out);
t_err	t_map_parse_blend_subtract(t_ft_json value, t_map_blend_subtract *out);
t_err	t_map_parse_material(t_ft_json value, t_map_material *out);
void	t_map_parse_render_options(t_ft_json value, t_map_render_options *out);

t_err	t_map_parse_get_optional_models(
			t_ft_json value, t_map_model ***out, size_t *out_count);
t_err	t_map_parse_get_optional_lights(
			t_ft_json value, t_map_light **out, size_t *out_count);
t_err	t_map_parse_get_optional_planes(
			t_ft_json value, t_map_plane **out, size_t *out_count);
t_err	t_map_parse_get_optional_quadrics(
			t_ft_json value, t_map_quadric **out, size_t *out_count);
void	t_map_parse_get_optional_specular_lobe(t_ft_json value, t_f *out);
void	t_map_parse_get_position(t_ft_json value, t_map_position *out);
void	t_map_parse_get_rotation(t_ft_json value, t_map_rotation *out);
void	t_map_parse_get_direction(t_ft_json value, t_map_normal *out);
void	t_map_parse_get_color(t_ft_json value, t_map_light_color *out);
void	t_map_parse_get_optional_position(t_ft_json value, t_map_position *out);
void	t_map_parse_get_optional_size(t_ft_json value, t_map_size *out);
void	t_map_parse_get_optional_rotation(t_ft_json value, t_map_rotation *out);
t_err	t_map_parse_get_optional_material(t_ft_json value, t_map_material *out);
void	t_map_parse_get_optional_color_material(
			t_ft_json value, t_map_color_material *out);
void	t_map_parse_get_optional_range(
			t_ft_json value, bool *out_has_range, t_f *out_range);
void	t_map_parse_get_optional_render_options(
			t_ft_json value, t_map_render_options *out);
void	t_map_parse_get_default_position(t_map_position *out);
void	t_map_parse_get_default_size(t_map_size *out);
void	t_map_parse_get_default_rotation(t_map_rotation *out);
t_err	t_map_parse_get_default_color(t_map_color **out);
t_err	t_map_parse_get_default_material(t_map_material *out);
void	t_map_parse_get_default_color_material(t_map_color_material *out);
void	t_map_parse_get_default_render_options(t_map_render_options *out);

#endif
