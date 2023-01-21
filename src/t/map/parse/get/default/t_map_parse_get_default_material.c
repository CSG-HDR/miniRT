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
#include "t_map_free.h"

static t_map_color	*color(void)
{
	t_map_color *const	result = wrap_malloc(sizeof(t_map_color));

	if (!result)
		return (NULL);
	result->color.type = T_MAP_COLOR_TYPE_COLOR;
	result->color.color = (t_f3){(t_f)1, (t_f)1, (t_f)1};
	return (result);
}

t_err	t_map_parse_get_default_material(t_map_material *out)
{
	out->ambient = color();
	out->diffuse = color();
	out->specular = color();
	if (!out->ambient || !out->diffuse || !out->specular)
	{
		if (!out->ambient)
			t_map_free_color(out->ambient);
		if (!out->diffuse)
			t_map_free_color(out->diffuse);
		if (!out->specular)
			t_map_free_color(out->specular);
		return (true);
	}
	out->specular_lobe = (t_f)1;
	return (false);
}
