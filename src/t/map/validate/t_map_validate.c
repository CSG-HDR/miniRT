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

#include "t_map_validate.h"

#include <stdbool.h>

#include "ft_json.h"

static bool	validate_models(t_ft_json value)
{
	size_t	count;

	if (!ft_json_is_list(value))
		return (false);
	count = ft_json_list_length(value);
	while (count--)
		if (!t_map_validate_model(ft_json_get_list(value, count)))
			return (false);
	return (true);
}

static bool	validate_lights(t_ft_json value)
{
	size_t	count;

	if (!ft_json_is_list(value))
		return (false);
	count = ft_json_list_length(value);
	while (count--)
		if (!t_map_validate_light(ft_json_get_list(value, count)))
			return (false);
	return (true);
}

static bool	validate_planes(t_ft_json value)
{
	size_t	count;

	if (!ft_json_is_list(value))
		return (false);
	count = ft_json_list_length(value);
	while (count--)
		if (!t_map_validate_plane(ft_json_get_list(value, count)))
			return (false);
	return (true);
}

static bool	validate_quadrics(t_ft_json value)
{
	size_t	count;

	if (!ft_json_is_list(value))
		return (false);
	count = ft_json_list_length(value);
	while (count--)
		if (!t_map_validate_quadric(ft_json_get_list(value, count)))
			return (false);
	return (true);
}

bool	t_map_validate(t_ft_json value)
{
	return (
		true
		&& ft_json_is_dict(value)
		&& (!ft_json_dict_has_key(value, "models")
			|| validate_models(ft_json_get_dict(value, "models")))
		&& (!ft_json_dict_has_key(value, "lights")
			|| validate_lights(ft_json_get_dict(value, "lights")))
		&& (!ft_json_dict_has_key(value, "planes")
			|| validate_planes(ft_json_get_dict(value, "planes")))
		&& (!ft_json_dict_has_key(value, "quadrics")
			|| validate_quadrics(ft_json_get_dict(value, "quadrics")))
		&& ft_json_dict_has_key(value, "camera")
		&& t_map_validate_camera(ft_json_get_dict(value, "camera"))
		&& ft_json_dict_has_key(value, "viewport")
		&& t_map_validate_viewport(ft_json_get_dict(value, "viewport"))
		&& (!ft_json_dict_has_key(value, "ambientLight")
			|| t_map_validate_light_color(
				ft_json_get_dict(value, "ambientLight")))
		&& (!ft_json_dict_has_key(value, "voidColor")
			|| t_map_validate_material_color(
				ft_json_get_dict(value, "voidColor")))
		&& t_map_validate_has_optional_render_options(value)
	);
}
