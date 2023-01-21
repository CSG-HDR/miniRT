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
#include <stdlib.h>

#include "wrap.h"
#include "ft_json.h"
#include "t_f.h"
#include "t_f3.h"
#include "t_map.h"
#include "t_map_free.h"

t_map_light	*l(t_ft_json value, size_t *out_count)
{
	const size_t		count = ft_json_list_length(value);
	t_map_light *const	result = wrap_malloc(sizeof(t_map_light) * count);
	size_t				i;

	if (!result)
		return (NULL);
	i = 0;
	while (i != count)
	{
		if (t_map_parse_light(ft_json_get_list(value, i), &result[i]))
		{
			t_map_free_lights(result, count);
			return (NULL);
		}
		i++;
	}
	*out_count = count;
	return (result);
}

void	optionals(t_ft_json value, t_map *result)
{
	const bool	has_ambient_light = ft_json_dict_has_key(value, "ambientLight");
	const bool	has_void_color = ft_json_dict_has_key(value, "voidColor");

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

t_err	t_map_parse(t_ft_json value, t_map **out)
{
	t_map *const	result = wrap_malloc(sizeof(t_map));

	if (!result)
		return (true);
	if (t_map_parse_models(ft_json_get_dict(value, "models"),
			&result->models, &result->model_count))
	{
		free(result);
		return (true);
	}
	result->lights = l(ft_json_get_dict(value, "lights"), &result->light_count);
	if (!result->lights)
	{
		t_map_free_models(result->models, result->model_count);
		free(result);
		return (true);
	}
	t_map_parse_camera(
		ft_json_get_dict(value, "camera"), &result->camera);
	t_map_parse_viewport(
		ft_json_get_dict(value, "viewport"), &result->viewport);
	optionals(value, result);
	*out = result;
	return (false);
}
