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

t_err	t_texture_manager_preload_model(
	t_texture_manager *self,
	t_map_model *model
)
{
	if (model->type == T_MAP_MODEL_TYPE_CONSTRUCTIVE)
		return (
			t_texture_manager_preload_constructive(
				self,
				model->constructive.constructive
			)
		);
	else
		return (
			t_texture_manager_preload_primitive(
				self,
				model->primitive.primitive
			)
		);
}
