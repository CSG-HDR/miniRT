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

t_f3	t_color_get(t_context *context, t_map_color *color, t_f x, t_f y);

t_f3	t_color_get_texture(
			t_context *context,
			t_map_texture texture,
			t_f x,
			t_f y);
t_f3	t_color_get_blend(
			t_context *context,
			t_map_blend blend,
			t_f x,
			t_f y);
t_f3	t_color_get_add(
			t_context *context,
			t_map_blend_add add,
			t_f x,
			t_f y);
t_f3	t_color_get_multiply(
			t_context *context,
			t_map_blend_multiply multiply,
			t_f x,
			t_f y);
t_f3	t_color_get_maximum(
			t_context *context,
			t_map_blend_maximum maximum,
			t_f x,
			t_f y);
t_f3	t_color_get_minimum(
			t_context *context,
			t_map_blend_minimum minimum,
			t_f x,
			t_f y);
t_f3	t_color_get_subtract(
			t_context *context,
			t_map_blend_subtract subtract,
			t_f x,
			t_f y);

#endif
