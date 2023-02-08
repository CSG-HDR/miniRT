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

#include "t_ray_primitive_ellipsoid.h"

#include "t_f.h"
#include "t_f3.h"
#include "t_map.h"

void	t_ray_primitive_ellipsoid_coord(
	t_map_position point,
	t_map_size size,
	t_f *out_x,
	t_f *out_y
)
{
	const t_f3	p = t_f3_div3(point, size);

	*out_x = t_f_rot(t_f_atan2(p.y, p.x));
	*out_y = (t_f_rot(t_f_asin(p.z)) + (t_f)0.25) * (t_f)2;
}
