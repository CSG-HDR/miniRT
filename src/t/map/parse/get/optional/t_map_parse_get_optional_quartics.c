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

#include <stddef.h>

#include "wrap.h"
#include "ft_json.h"
#include "t_map.h"

t_err	t_map_parse_get_optional_quartics(
	t_ft_json value,
	t_map_quartic **out,
	size_t *out_count
)
{
	if (!ft_json_dict_has_key(value, "quartics"))
	{
		*out_count = 0;
		return (false);
	}
	return (
		t_map_parse_quartics(
			ft_json_get_dict(value, "quartics"),
			out,
			out_count
		)
	);
}
