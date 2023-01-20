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
#include "t_map.h"
#include "t_map_free.h"

t_map	*t_map_parse(t_ft_json value)
{
	t_map *const	result = wrap_malloc(sizeof(t_map));

	if (!result)
		return (NULL);
	result->models = t_map_parse_models(
			ft_json_get_dict(value, "models"), &result->model_count);
	if (!result->models)
	{
		free(result);
		return (NULL);
	}
	result->lights = t_map_parse_lights(
			ft_json_get_dict(value, "lights"), &result->light_count);
	{
		t_map_free_models(result->models, result->model_count);
		free(result);
		return (NULL);
	}
	result->camera
		= t_map_parse_camera(ft_json_get_dict(value, "camera"));
	result->viewport
		= t_map_parse_viewport(ft_json_get_dict(value, "viewport"));
}
