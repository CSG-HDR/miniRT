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

#include "t_map_free.h"

#include "wrap.h"
#include "t_map.h"

void	t_map_free_primitive(t_map_primitive value)
{
	if (*value.type == T_MAP_PRIMITIVE_TYPE_SPHERE)
	{
		t_map_free_sphere(value.sphere->sphere);
		wrap_free(value.sphere);
	}
	else
	{
		t_map_free_cube(value.cube->cube);
		wrap_free(value.cube);
	}
}
