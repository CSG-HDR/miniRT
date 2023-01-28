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
#include "t_f.h"
#include "t_f3.h"
#include "t_map.h"

static void	optional_material_color(
	t_ft_json value,
	const char *key,
	t_map_material_color *out
)
{
	if (ft_json_dict_has_key(value, key))
		t_map_parse_material_color(ft_json_get_dict(value, key), out);
	else
		*out = (t_f3){(t_f)1, (t_f)1, (t_f)1};
}

void	t_map_parse_color_material(t_ft_json value, t_map_color_material *out)
{
	optional_material_color(value, "ambient", &out->ambient);
	optional_material_color(value, "diffuse", &out->diffuse);
	optional_material_color(value, "specular", &out->specular);
	t_map_parse_get_optional_specular_lobe(value, &out->specular_lobe);
}
