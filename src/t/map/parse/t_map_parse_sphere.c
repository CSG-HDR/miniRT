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

#include "t_map_parse.h"

#include "ft_json.h"
#include "t_f.h"
#include "t_map.h"

t_err	t_map_parse_sphere(t_ft_json value, t_map_sphere *out)
{
	t_map_parse_position(ft_json_get_dict(value, "position"), &out->position);
	out->radius = (t_f)ft_json_get_number(ft_json_get_dict(value, "radius"));
	return (t_map_parse_material(
			ft_json_get_dict(value, "material"), &out->material));
}
