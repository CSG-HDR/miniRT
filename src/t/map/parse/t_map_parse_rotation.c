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
#include "t_f3.h"
#include "t_map.h"

void	t_map_parse_rotation(t_ft_json value, t_map_rotation *out)
{
	const t_f	x = (t_f)ft_json_get_number(ft_json_get_list(value, 0));
	const t_f	y = (t_f)ft_json_get_number(ft_json_get_list(value, 0));
	const t_f	z = (t_f)ft_json_get_number(ft_json_get_list(value, 0));
	t_f			real_z;

	real_z = z;
	if (z < 0)
		real_z = z + 1;
	out->x = t_f_rad(x);
	out->y = t_f_rad(y);
	out->z = t_f_rad(real_z);
}
