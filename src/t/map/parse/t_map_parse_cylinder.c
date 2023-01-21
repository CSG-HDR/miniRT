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

static t_err	zero(t_map_cylinder *out)
{
	if (t_map_parse_get_default_material(&out->material_side))
		return (true);
	if (t_map_parse_get_default_material(&out->material_top))
	{
		t_map_free_material(out->material_side);
		return (true);
	}
	if (t_map_parse_get_default_material(&out->material_bottom))
	{
		t_map_free_material(out->material_side);
		t_map_free_material(out->material_top);
		return (true);
	}
	return (false);
}

static t_err	multiple(t_ft_json value, t_map_cylinder *out)
{
	if (t_map_parse_material(ft_json_get_list(value, 0), &out->material_side))
		return (true);
	if (t_map_parse_material(ft_json_get_list(value, 1), &out->material_top))
	{
		t_map_free_material(out->material_side);
		return (true);
	}
	if (t_map_parse_material(ft_json_get_list(value, 2), &out->material_bottom))
	{
		t_map_free_material(out->material_side);
		t_map_free_material(out->material_top);
		return (true);
	}
	return (false);
}

static t_err	single(t_ft_json value, t_map_cylinder *out)
{
	if (t_map_parse_material(value, &out->material_side))
		return (true);
	if (t_map_parse_material(value, &out->material_top))
	{
		t_map_free_material(out->material_side);
		return (true);
	}
	if (t_map_parse_material(value, &out->material_bottom))
	{
		t_map_free_material(out->material_side);
		t_map_free_material(out->material_top);
		return (true);
	}
	return (false);
}

t_err	t_map_parse_cylinder(t_ft_json value, t_map_cylinder *out)
{
	t_map_parse_position(ft_json_get_dict(value, "position"), &out->position);
	t_map_parse_size(ft_json_get_dict(value, "size"), &out->size);
	t_map_parse_rotation(ft_json_get_dict(value, "rotation"), &out->rotation);
	if (!ft_json_dict_has_key(value, "material"))
		return (zero(out));
	if (ft_json_is_list(ft_json_get_dict(value, "material")))
		return (multiple(ft_json_get_dict(value, "material"), out));
	return (single(ft_json_get_dict(value, "material"), out));
}
