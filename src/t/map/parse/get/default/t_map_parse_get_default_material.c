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
#include "t_map.h"
#include "t_map_free.h"

t_err	t_map_parse_get_default_material(t_map_material *out)
{
	if (t_map_parse_get_default_color(&out->ambient))
		return (true);
	if (t_map_parse_get_default_color(&out->diffuse))
	{
		t_map_free_color(out->ambient);
		return (true);
	}
	if (t_map_parse_get_default_color(&out->specular))
	{
		t_map_free_color(out->ambient);
		t_map_free_color(out->diffuse);
		return (true);
	}
	out->specular_lobe = (t_f)1;
	return (false);
}
