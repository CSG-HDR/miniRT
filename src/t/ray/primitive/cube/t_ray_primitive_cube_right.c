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

#include "t_ray_primitive_cube.h"

#include "ft_types.h"
#include "t_map.h"
#include "t_ray.h"

t_err	t_ray_primitive_cube_right(
			t_ray ray,
			t_map_cube cube,
			t_ray_hit_records_builder *builder)
{
	(void) ray;
	(void) cube;
	(void) builder;
	return (false);
}
