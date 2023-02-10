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

#ifndef T_RAY_PRIMITIVE_CUBE_H
# define T_RAY_PRIMITIVE_CUBE_H

# include "t_ray.h"
# include "ft_types.h"

t_err	t_ray_primitive_cube_top(
			t_ray ray,
			t_map_cube cube,
			t_ray_hit_records_builder *builder);
t_err	t_ray_primitive_cube_bottom(
			t_ray ray,
			t_map_cube cube,
			t_ray_hit_records_builder *builder);
t_err	t_ray_primitive_cube_left(
			t_ray ray,
			t_map_cube cube,
			t_ray_hit_records_builder *builder);
t_err	t_ray_primitive_cube_right(
			t_ray ray,
			t_map_cube cube,
			t_ray_hit_records_builder *builder);
t_err	t_ray_primitive_cube_front(
			t_ray ray,
			t_map_cube cube,
			t_ray_hit_records_builder *builder);
t_err	t_ray_primitive_cube_back(
			t_ray ray,
			t_map_cube cube,
			t_ray_hit_records_builder *builder);
t_err	t_ray_primitive_cube_inside(
			t_ray ray,
			t_map_cube cube,
			t_ray_hit_records_builder *builder);

#endif
