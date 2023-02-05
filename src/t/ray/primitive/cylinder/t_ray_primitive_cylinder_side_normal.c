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

#include "t_ray_primitive_cylinder.h"

#include "t_f3.h"
#include "t_map.h"

/*
 * f(x) = Ax^2 + By^2
 * f'(x) = 2Ax
 */
static t_f	x(t_vars l, t_map_position point)
{
	return (2 * l.a * point.x);
}

/*
 * f(y) = Ax^2 + By^2
 * f'(y) = 2By
 */
static t_f	y(t_vars l, t_map_position point)
{
	return (2 * l.b * point.y);
}

t_map_normal	t_ray_primitive_cylinder_side_normal(
	t_vars l,
	t_map_position point
)
{
	return (t_f3_unit((t_f3){x(l, point), y(l, point), 0}));
}
