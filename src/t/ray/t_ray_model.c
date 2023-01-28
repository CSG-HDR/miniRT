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

#include "t_ray.h"

#include "ft_types.h"
#include "t_map.h"

t_err	t_ray_model(
	t_ray ray,
	t_map_model *model,
	t_ray_hit_records *out
)
{
	if (model->type == T_MAP_MODEL_TYPE_CONSTRUCTIVE)
		return (t_ray_constructive(ray, model->constructive.constructive, out));
	else
		return (t_ray_primitive(ray, model->primitive.primitive, out));
}
