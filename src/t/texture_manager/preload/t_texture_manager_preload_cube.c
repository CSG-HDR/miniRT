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

#include "t_texture_manager.h"

#include "t_map.h"

t_err	t_texture_manager_preload_cube(
	t_texture_manager *self,
	t_map_cube cube
)
{
	return (
		false
		|| t_texture_manager_preload_material(self, cube.material_top)
		|| t_texture_manager_preload_material(self, cube.material_bottom)
		|| t_texture_manager_preload_material(self, cube.material_left)
		|| t_texture_manager_preload_material(self, cube.material_right)
		|| t_texture_manager_preload_material(self, cube.material_front)
		|| t_texture_manager_preload_material(self, cube.material_back)
	);
}
