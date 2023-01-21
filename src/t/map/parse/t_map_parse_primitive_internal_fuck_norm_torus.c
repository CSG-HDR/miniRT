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

#include "wrap.h"
#include "ft_json.h"
#include "t_map.h"

t_err	t_map_parse_primitive_internal_fuck_norm_torus(
	t_ft_json value,
	t_map_primitive_torus **out
)
{
	t_map_primitive_torus *const	result
		= wrap_malloc(sizeof(t_map_primitive_torus));

	if (!result)
		return (true);
	result->type = T_MAP_PRIMITIVE_TYPE_TORUS;
	if (t_map_parse_torus(value, &result->torus))
	{
		wrap_free(result);
		return (true);
	}
	*out = result;
	return (false);
}
