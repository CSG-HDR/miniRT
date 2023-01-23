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
	*out = t_f3_unit((t_f3){
			t_f_rad((t_f)ft_json_get_number(ft_json_get_list(value, 0))),
			t_f_rad((t_f)ft_json_get_number(ft_json_get_list(value, 1))),
			t_f_rad((t_f)ft_json_get_number(ft_json_get_list(value, 2))),
		});
}
