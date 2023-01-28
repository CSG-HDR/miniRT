/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_parse_optional_models.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2023/01/28 23:32:35 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_map_parse.h"

#include <stddef.h>

#include "wrap.h"
#include "ft_json.h"
#include "t_map.h"
#include "t_map_free.h"

t_err	t_map_parse_get_optional_models(
	t_ft_json value,
	t_map_model ***out,
	size_t *out_count
)
{
	size_t		i;

	if (!ft_json_dict_has_key(value, "models"))
	{
		*out_count = 0;
		return (false);
	}
	*out_count = ft_json_list_length(ft_json_get_dict(value, "models"));
	*out = wrap_malloc(sizeof(t_map_model *) * *out_count);
	if (!*out)
		return (NULL);
	i = 0;
	while (i != *out_count)
	{
		if (t_map_parse_model(ft_json_get_list(
					ft_json_get_dict(value, "models"), i), out[i]))
		{
			t_map_free_models(*out, i);
			return (true);
		}
		i++;
	}
	return (false);
}