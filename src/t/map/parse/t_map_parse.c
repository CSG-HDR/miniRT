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
#include <stddef.h>

#include "wrap.h"
#include "ft_json.h"
#include "t_f.h"
#include "t_f3.h"
#include "t_map.h"
#include "t_map_free.h"

void	etc(t_ft_json value, t_map *result)
{
	const bool	has_ambient_light = ft_json_dict_has_key(value, "ambientLight");
	const bool	has_void_color = ft_json_dict_has_key(value, "voidColor");

	t_map_parse_viewport(
		ft_json_get_dict(value, "viewport"), &result->viewport);
	t_map_parse_camera(
		ft_json_get_dict(value, "camera"), &result->camera, &result->viewport);
	if (has_ambient_light)
		t_map_parse_light_color(
			ft_json_get_dict(value, "ambientLight"), &result->ambient_light);
	else
		result->ambient_light = (t_f3){(t_f)0, (t_f)0, (t_f)0};
	if (has_void_color)
		t_map_parse_light_color(
			ft_json_get_dict(value, "voidColor"), &result->void_color);
	else
		result->void_color = (t_f3){(t_f)0, (t_f)0, (t_f)0};
}

static t_err	pre(t_ft_json value, t_map *out)
{
	if (t_map_parse_get_optional_models(
			value, &out->models, &out->model_count))
		return (true);
	if (t_map_parse_get_optional_lights(
			value, &out->lights, &out->light_count))
	{
		t_map_free_models(out->models, out->model_count);
		return (true);
	}
	if (t_map_parse_get_optional_planes(
			value, &out->planes, &out->plane_count))
	{
		t_map_free_models(out->models, out->model_count);
		t_map_free_lights(out->lights, out->light_count);
		return (true);
	}
	if (t_map_parse_get_optional_quadrics(
			value, &out->quadrics, &out->quadric_count))
	{
		t_map_free_models(out->models, out->model_count);
		t_map_free_lights(out->lights, out->light_count);
		t_map_free_planes(out->planes, out->plane_count);
		return (true);
	}
	return (false);
}

t_err	t_map_parse(t_ft_json value, t_map **out)
{
	t_map *const	result = wrap_malloc(sizeof(t_map));

	if (!result)
		return (true);
	if (pre(value, result))
	{
		wrap_free(result);
		return (true);
	}
	etc(value, result);
	*out = result;
	return (false);
}
