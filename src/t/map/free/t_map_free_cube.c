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

#include "t_map.h"

void	t_map_free_cube(t_map_cube value)
{
	t_map_free_material(value.material_top);
	t_map_free_material(value.material_bottom);
	t_map_free_material(value.material_left);
	t_map_free_material(value.material_right);
	t_map_free_material(value.material_front);
	t_map_free_material(value.material_back);
}
