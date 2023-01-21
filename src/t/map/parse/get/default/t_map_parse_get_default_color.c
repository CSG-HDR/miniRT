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
#include "t_f.h"
#include "t_f3.h"
#include "t_map.h"

t_err	t_map_parse_get_default_color(t_map_color **out)
{
	t_map_color *const	result = wrap_malloc(sizeof(t_map_color));

	if (!result)
		return (true);
	result->color.type = T_MAP_COLOR_TYPE_COLOR;
	result->color.color = (t_f3){(t_f)1, (t_f)1, (t_f)1};
	*out = result;
	return (false);
}
