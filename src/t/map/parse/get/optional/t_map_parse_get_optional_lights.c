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
#include "t_map_free.h"

t_err	t_map_parse_get_optional_lights(
	t_ft_json value,
	t_map_light **out,
	size_t *out_count
)
{
	size_t		i;

	if (!ft_json_dict_has_key(value, "lights"))
	{
		*out_count = 0;
		return (false);
	}
	*out_count = ft_json_list_length(ft_json_get_dict(value, "lights"));
	*out = wrap_malloc(sizeof(t_map_light) * *out_count);
	if (!*out)
		return (true);
	i = 0;
	while (i != *out_count)
	{
		if (t_map_parse_light(ft_json_get_list(
					ft_json_get_dict(value, "lights"), i), &(*out)[i]))
		{
			t_map_free_lights(*out, i);
			return (true);
		}
		i++;
	}
	return (false);
}
