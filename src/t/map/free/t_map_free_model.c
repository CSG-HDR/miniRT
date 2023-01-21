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

void	t_map_free_model(t_map_model *value)
{
	if (value->type == T_MAP_MODEL_TYPE_CONSTRUCTIVE)
		t_map_free_constructive(value->constructive.constructive);
	else
		t_map_free_primitive(value->primitive.primitive);
	wrap_free(value);
}
