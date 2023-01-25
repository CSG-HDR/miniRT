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

#include <math.h>
#include "ft_cstring.h"
#include "ft_json.h"
#include "t_f.h"
#include "t_map.h"

static t_map_fov_type	type(t_ft_json value)
{
	if (!ft_json_dict_has_key(value, "fovType"))
		return (T_MAP_FOV_TYPE_MAX);
	if (ft_cstring_equals(
			ft_json_get_string(ft_json_get_dict(value, "fovType")), "max"))
		return (T_MAP_FOV_TYPE_MAX);
	if (ft_cstring_equals(
			ft_json_get_string(ft_json_get_dict(value, "fovType")), "min"))
		return (T_MAP_FOV_TYPE_MIN);
	if (ft_cstring_equals(
			ft_json_get_string(ft_json_get_dict(value, "fovType")), "x"))
		return (T_MAP_FOV_TYPE_X);
	else
		return (T_MAP_FOV_TYPE_Y);
}

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

void	t_map_parse_camera(
	t_ft_json value,
	t_map_camera *out,
	t_map_viewport *viewport
)
{
	t_map_parse_get_position(value, &out->position);
	t_map_parse_get_rotation(value, &out->rotation);
	out->fov = t_f_rad((t_f)ft_json_get_number(ft_json_get_dict(value, "fov")));
	out->fov_type = type(value);
	calculate_fov(viewport, out->fov, out->fov_type, out);
	out->focal_len = tan(out->fov / 2.0 * M_PI / 180.0) * viewport->actual_width / 2;
}
