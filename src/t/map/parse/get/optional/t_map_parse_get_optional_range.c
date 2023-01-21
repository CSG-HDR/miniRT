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
#include "t_map.h"

void	t_map_parse_get_optional_range(
	t_ft_json value,
	bool *out_has_range,
	t_f *out_range
)
{
	*out_has_range = ft_json_dict_has_key(value, "range");
	if (*out_has_range)
		*out_range = (t_f)ft_json_get_number(ft_json_get_dict(value, "range"));
}
