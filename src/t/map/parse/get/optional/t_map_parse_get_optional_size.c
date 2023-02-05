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

void	t_map_parse_get_optional_size(
	t_ft_json value,
	t_map_size *out
)
{
	if (ft_json_dict_has_key(value, "size"))
		t_map_parse_size(ft_json_get_dict(value, "size"), out);
	else
		t_map_parse_get_default_size(out);
}
