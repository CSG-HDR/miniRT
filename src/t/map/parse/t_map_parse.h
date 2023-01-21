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

# include "ft_json.h"
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
t_err	t_map_parse_sphere(t_ft_json value, t_map_sphere *out);
t_err	t_map_parse_cube(t_ft_json value, t_map_cube *out);
t_err	t_map_parse_lights(
			t_ft_json value, t_map_light **out, size_t *out_count);
t_err	t_map_parse_light(t_ft_json value, t_map_light *out);
t_err	t_map_parse_planes(
			t_ft_json value, t_map_plane **out, size_t *out_count);
t_err	t_map_parse_plane(t_ft_json value, t_map_plane *out);
void	t_map_parse_point(t_ft_json value, t_map_point *out);
void	t_map_parse_directional(t_ft_json value, t_map_directional *out);
void	t_map_parse_spot(t_ft_json value, t_map_spot *out);
void	t_map_parse_camera(t_ft_json value, t_map_camera *out);
void	t_map_parse_viewport(t_ft_json value, t_map_viewport *out);
void	t_map_parse_position(t_ft_json value, t_map_position *out);
void	t_map_parse_size(t_ft_json value, t_map_size *out);
void	t_map_parse_rotation(t_ft_json value, t_map_rotation *out);
void	t_map_parse_normal(t_ft_json value, t_map_rotation *out);
void	t_map_parse_light_color(t_ft_json value, t_map_light_color *out);
void	t_map_parse_material_color(t_ft_json value, t_map_material_color *out);
t_err	t_map_parse_color(t_ft_json value, t_map_color *out);
t_err	t_map_parse_normal_map(t_ft_json value, t_map_normal_map *out);
t_err	t_map_parse_texture(t_ft_json value, t_map_texture *out);
t_err	t_map_parse_material(t_ft_json value, t_map_material *out);

#endif
