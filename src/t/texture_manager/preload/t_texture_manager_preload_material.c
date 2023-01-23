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

t_err	t_texture_manager_preload_material(
	t_texture_manager *self,
	t_map_material material
)
{
	return (
		false
		|| t_texture_manager_preload_color(self, material.ambient)
		|| t_texture_manager_preload_color(self, material.diffuse)
		|| t_texture_manager_preload_color(self, material.specular)
		|| (
			material.has_normal
			&& t_texture_manager_preload_normal_map(self, material.normal)
		)
	);
}
