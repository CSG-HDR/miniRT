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

#include "ft_json.h"
#include "t_map.h"
#include "t_map_free.h"

static t_err	pre(t_map_cube *out)
{
	if (t_map_parse_get_default_material(&out->material_top))
		return (true);
	if (t_map_parse_get_default_material(&out->material_bottom))
	{
		t_map_free_material(out->material_top);
		return (true);
	}
	if (t_map_parse_get_default_material(&out->material_left))
	{
		t_map_free_material(out->material_top);
		t_map_free_material(out->material_bottom);
		return (true);
	}
	if (t_map_parse_get_default_material(&out->material_right))
	{
		t_map_free_material(out->material_top);
		t_map_free_material(out->material_bottom);
		t_map_free_material(out->material_left);
		return (true);
	}
	return (false);
}

t_err	t_map_parse_cube_internal_by_fucking_norm(t_map_cube *out)
{
	if (pre(out))
		return (true);
	if (t_map_parse_get_default_material(&out->material_front))
	{
		t_map_free_material(out->material_top);
		t_map_free_material(out->material_bottom);
		t_map_free_material(out->material_left);
		t_map_free_material(out->material_right);
		return (true);
	}
	if (t_map_parse_get_default_material(&out->material_back))
	{
		t_map_free_material(out->material_top);
		t_map_free_material(out->material_bottom);
		t_map_free_material(out->material_left);
		t_map_free_material(out->material_right);
		t_map_free_material(out->material_back);
		return (true);
	}
	return (false);
}
