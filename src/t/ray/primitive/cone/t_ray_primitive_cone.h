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

#ifndef T_RAY_PRIMITIVE_CONE_H
# define T_RAY_PRIMITIVE_CONE_H

# include "t_ray.h"
# include "ft_types.h"

/**
 * f(x, y, z) = x^2/a^2 + y^2/b^2 - z^2/c^2 = 0
 * f(ray.position + ray.direction * distance) = 0
 * f(p+ut, q+vt, r+wt) = 0
 *
 * A = 1/a^2, B = 1/b^2, C = 1/c^2
 * Ax^2 + By^2 - Cz^2 = 0
 * Ap^2 + 2Aput + Au^2t^2 + Bq^2 + 2Bqvt + Bv^2t^2 - Cr^2 - 2Crwt - Cw^2t^2 = 0
 * X = Au^2 + Bv^2 - Cw^2
 * Y = 2Apu + 2Bqv - 2Crw
 * Z = Ap^2 + Bq^2 - Cr^2
 * t = (-Y +- sqrt(Y^2 - 4XZ)) / 2X
 */
typedef struct s_vars
{
	t_f			a;
	t_f			b;
	t_f			c;
	t_f			p;
	t_f			q;
	t_f			r;
	t_f			u;
	t_f			v;
	t_f			w;
	t_f			x;
	t_f			y;
	t_f			z;
	t_f			y2_4xz;
	bool		hit;
	bool		has_record;
	t_f			sqrt_y2_4xz;
	t_map_cone	self;
}	t_vars;

t_err			t_ray_primitive_cone_inside(
					t_ray ray,
					t_map_cone cone,
					t_ray_hit_records_builder *builder);
t_err			t_ray_primitive_cone_side(
					t_ray ray,
					t_map_cone cone,
					t_ray_hit_records_builder *builder);
t_map_normal	t_ray_primitive_cone_side_normal(
					t_vars l,
					t_map_position point);
t_err			t_ray_primitive_cone_bottom(
					t_ray ray,
					t_map_cone cone,
					t_ray_hit_records_builder *builder);

#endif
