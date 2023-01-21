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

static t_err	pre_multiple(t_ft_json value, t_map_cube *out)
{
	if (t_map_parse_material(ft_json_get_list(value, 0), &out->material_top))
		return (true);
	if (t_map_parse_material(ft_json_get_list(value, 1), &out->material_bottom))
	{
		t_map_free_material(out->material_top);
		return (true);
	}
	if (t_map_parse_material(ft_json_get_list(value, 2), &out->material_left))
	{
		t_map_free_material(out->material_top);
		t_map_free_material(out->material_bottom);
		return (true);
	}
	if (t_map_parse_material(ft_json_get_list(value, 3), &out->material_right))
	{
		t_map_free_material(out->material_top);
		t_map_free_material(out->material_bottom);
		t_map_free_material(out->material_left);
		return (true);
	}
	return (false);
}

static t_err	multiple(t_ft_json value, t_map_cube *out)
{
	if (!pre_multiple(value, out))
		return (true);
	if (t_map_parse_material(ft_json_get_list(value, 4), &out->material_front))
	{
		t_map_free_material(out->material_top);
		t_map_free_material(out->material_bottom);
		t_map_free_material(out->material_left);
		t_map_free_material(out->material_right);
		return (true);
	}
	if (t_map_parse_material(ft_json_get_list(value, 5), &out->material_back))
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

static t_err	pre_single(t_ft_json value, t_map_cube *out)
{
	if (t_map_parse_material(value, &out->material_top))
		return (true);
	if (t_map_parse_material(value, &out->material_bottom))
	{
		t_map_free_material(out->material_top);
		return (true);
	}
	if (t_map_parse_material(value, &out->material_left))
	{
		t_map_free_material(out->material_top);
		t_map_free_material(out->material_bottom);
		return (true);
	}
	if (t_map_parse_material(value, &out->material_right))
	{
		t_map_free_material(out->material_top);
		t_map_free_material(out->material_bottom);
		t_map_free_material(out->material_left);
		return (true);
	}
	return (false);
}

static t_err	single(t_ft_json value, t_map_cube *out)
{
	if (!pre_single(value, out))
		return (true);
	if (t_map_parse_material(value, &out->material_front))
	{
		t_map_free_material(out->material_top);
		t_map_free_material(out->material_bottom);
		t_map_free_material(out->material_left);
		t_map_free_material(out->material_right);
		return (true);
	}
	if (t_map_parse_material(value, &out->material_back))
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

t_err	t_map_parse_cube(t_ft_json value, t_map_cube *out)
{
	t_map_parse_position(ft_json_get_dict(value, "position"), &out->position);
	t_map_parse_size(ft_json_get_dict(value, "size"), &out->size);
	t_map_parse_rotation(ft_json_get_dict(value, "rotation"), &out->rotation);
	if (ft_json_is_list(ft_json_get_dict(value, "material")))
		return (multiple(ft_json_get_dict(value, "material"), out));
	return (single(ft_json_get_dict(value, "material"), out));
}
