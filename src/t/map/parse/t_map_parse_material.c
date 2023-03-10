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

#include <stdbool.h>

#include "ft_json.h"
#include "t_map.h"
#include "t_map_free.h"

static t_err	optional_color(
	t_ft_json value,
	const char *key,
	t_map_color **out
)
{
	if (ft_json_dict_has_key(value, key))
		return (t_map_parse_color(ft_json_get_dict(value, key), out));
	else
		return (t_map_parse_get_default_color(out));
}

static t_err	optional_normal(
	t_ft_json value,
	bool *out_has_normal,
	t_map_normal_map *out_normal
)
{
	*out_has_normal = ft_json_dict_has_key(value, "normal");
	return (
		*out_has_normal
		&& t_map_parse_normal_map(ft_json_get_dict(value, "normal"), out_normal)
	);
}

t_err	t_map_parse_material(t_ft_json value, t_map_material *out)
{
	if (optional_color(value, "ambient", &out->ambient))
		return (true);
	if (optional_color(value, "diffuse", &out->diffuse))
	{
		t_map_free_color(out->ambient);
		return (true);
	}
	if (optional_color(value, "specular", &out->specular))
	{
		t_map_free_color(out->ambient);
		t_map_free_color(out->diffuse);
		return (true);
	}
	t_map_parse_get_optional_specular_lobe(value, &out->specular_lobe);
	if (optional_normal(value, &out->has_normal, &out->normal))
	{
		t_map_free_color(out->ambient);
		t_map_free_color(out->diffuse);
		t_map_free_color(out->specular);
		return (true);
	}
	return (false);
}
