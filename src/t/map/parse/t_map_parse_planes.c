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

t_err	t_map_parse_planes(
	t_ft_json value,
	t_map_plane **out,
	size_t *out_count
)
{
	const size_t		count = ft_json_list_length(value);
	t_map_plane *const	result = wrap_malloc(sizeof(t_map_plane *) * count);
	size_t				i;

	if (!result)
		return (true);
	i = 0;
	while (i != count)
	{
		if (t_map_parse_plane(ft_json_get_list(value, i), &result[i]))
		{
			t_map_free_planes(result, count);
			return (NULL);
		}
		i++;
	}
	*out = result;
	*out_count = count;
	return (false);
}
