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

#include "t_f3.h"
#include "t_map_parse.h"

#include <math.h>
#include "ft_cstring.h"
#include "ft_json.h"
#include "t_f.h"
#include "t_map.h"
#include "t_map_validate.h"

static void	calculate_fov_x(
	t_map_viewport *viewport,
	t_map_angle fov_x,
	t_map_camera *result
)
{
	const t_f	half_fov_x = fov_x / 2;
	const t_f	x = t_f_tan(half_fov_x);
	const t_f	y = x / viewport->width * viewport->height;
	const t_f	half_fov_y = t_f_atan(y);
	const t_f	fov_y = half_fov_y * 2;

	result->fov_x = fov_x;
	result->fov_y = fov_y;
}

static void	calculate_fov_y(
	t_map_viewport *viewport,
	t_map_angle fov_y,
	t_map_camera *result
)
{
	const t_f	half_fov_y = fov_y / 2;
	const t_f	y = t_f_tan(half_fov_y);
	const t_f	x = y / viewport->height * viewport->width;
	const t_f	half_fov_x = t_f_atan(x);
	const t_f	fov_x = half_fov_x * 2;

	result->fov_x = fov_x;
	result->fov_y = fov_y;
}

static void	calculate_fov(
	t_map_viewport *viewport,
	t_map_angle fov,
	t_map_fov_type type,
	t_map_camera *result
)
{
	if (type == T_MAP_FOV_TYPE_MAX)
	{
		if (viewport->width > viewport->height)
			calculate_fov_x(viewport, fov, result);
		else
			calculate_fov_y(viewport, fov, result);
	}
	else if (type == T_MAP_FOV_TYPE_MIN)
	{
		if (viewport->width < viewport->height)
			calculate_fov_x(viewport, fov, result);
		else
			calculate_fov_y(viewport, fov, result);
	}
	else if (type == T_MAP_FOV_TYPE_X)
	{
		calculate_fov_x(viewport, fov, result);
	}
	else
	{
		calculate_fov_y(viewport, fov, result);
	}
}

static t_map_rotation	rotation(t_ft_json value, t_map_position position)
{
	t_map_rotation	rotation;
	t_map_normal	normal;
	t_map_position	look_at;

	if (t_map_validate_has_type(value, "rotation"))
	{
		t_map_parse_rotation(ft_json_get_dict(value, "rotation"), &rotation);
		return (rotation);
	}
	if (t_map_validate_has_type(value, "normal"))
	{
		t_map_parse_normal(ft_json_get_dict(value, "normal"), &normal);
		return (t_f3_to_angle(normal));
	}
	else
	{
		t_map_parse_position(ft_json_get_dict(value, "lookAt"), &look_at);
		normal = t_f3_sub(look_at, position);
		return (t_f3_to_angle(normal));
	}
}

void	t_map_parse_camera(
	t_ft_json value,
	t_map_camera *out,
	t_map_viewport *viewport
)
{
	if (!ft_json_dict_has_key(value, "fovType"))
		out->fov_type = T_MAP_FOV_TYPE_MAX;
	else if (ft_cstring_equals(
			ft_json_get_string(ft_json_get_dict(value, "fovType")), "max"))
		out->fov_type = T_MAP_FOV_TYPE_MAX;
	else if (ft_cstring_equals(
			ft_json_get_string(ft_json_get_dict(value, "fovType")), "min"))
		out->fov_type = T_MAP_FOV_TYPE_MIN;
	else if (ft_cstring_equals(
			ft_json_get_string(ft_json_get_dict(value, "fovType")), "x"))
		out->fov_type = T_MAP_FOV_TYPE_X;
	else
		out->fov_type = T_MAP_FOV_TYPE_Y;
	t_map_parse_get_position(value, &out->position);
	out->rotation
		= rotation(ft_json_get_dict(value, "rotation"), out->position);
	out->fov = t_f_rad((t_f)ft_json_get_number(ft_json_get_dict(value, "fov")));
	calculate_fov(viewport, out->fov, out->fov_type, out);
}
