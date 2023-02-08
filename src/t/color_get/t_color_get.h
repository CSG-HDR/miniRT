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

#ifndef T_COLOR_GET_H
# define T_COLOR_GET_H

# include "t.h"
# include "t_f3.h"
# include "t_map.h"
# include "t_ray.h"

t_f3					t_color_get(
							const t_context *context,
							t_map_color *color,
							t_f x,
							t_f y);
t_map_color_material	t_color_get_ray_material(
							const t_context *context,
							t_ray_material color,
							t_f x,
							t_f y);

t_f3					t_color_get_texture(
							const t_context *context,
							t_map_texture texture,
							t_f x,
							t_f y);
t_f3					t_color_get_blend(
							const t_context *context,
							t_map_blend blend,
							t_f x,
							t_f y);
t_f3					t_color_get_add(
							const t_context *context,
							t_map_blend_add add,
							t_f x,
							t_f y);
t_f3					t_color_get_multiply(
							const t_context *context,
							t_map_blend_multiply multiply,
							t_f x,
							t_f y);
t_f3					t_color_get_maximum(
							const t_context *context,
							t_map_blend_maximum maximum,
							t_f x,
							t_f y);
t_f3					t_color_get_minimum(
							const t_context *context,
							t_map_blend_minimum minimum,
							t_f x,
							t_f y);
t_f3					t_color_get_subtract(
							const t_context *context,
							t_map_blend_subtract subtract,
							t_f x,
							t_f y);

typedef struct s_color_get_context
{
	const t_context			*context;
	t_map_color_material	material;
	t_ray					ray;
	t_ray_hit_record		record;
}	t_color_get_context;

t_err					t_color_get_color(
							const t_context *context,
							t_ray ray,
							t_ray_hit_record record,
							t_f3 *out);
t_err					t_color_get_color_light(
							const t_color_get_context *context,
							t_map_light light,
							t_f3 *out);
t_err					t_color_get_color_light_point(
							const t_color_get_context *context,
							t_map_point light,
							t_f3 *out);
t_err					t_color_get_color_light_directional(
							const t_color_get_context *context,
							t_map_directional light,
							t_f3 *out);
t_err					t_color_get_color_light_spot(
							const t_color_get_context *context,
							t_map_spot light,
							t_f3 *out);
t_f3					t_color_get_util_reflect(
							const t_map_normal incidence,
							const t_map_normal normal);

#endif
