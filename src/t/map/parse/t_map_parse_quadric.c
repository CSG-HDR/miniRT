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

static void	list(t_ft_json value, t_map_quadric *out)
{
	out->a = ft_json_get_number(ft_json_get_list(value, 0));
	out->b = ft_json_get_number(ft_json_get_list(value, 1));
	out->c = ft_json_get_number(ft_json_get_list(value, 2));
	out->d = ft_json_get_number(ft_json_get_list(value, 3));
	out->e = ft_json_get_number(ft_json_get_list(value, 4));
	out->f = ft_json_get_number(ft_json_get_list(value, 5));
	out->g = ft_json_get_number(ft_json_get_list(value, 6));
	out->h = ft_json_get_number(ft_json_get_list(value, 7));
	out->i = ft_json_get_number(ft_json_get_list(value, 8));
	out->j = ft_json_get_number(ft_json_get_list(value, 9));
}

static void	dict(t_ft_json value, t_map_quadric *out)
{
	out->a = ft_json_get_number(ft_json_get_dict(value, "A"));
	out->b = ft_json_get_number(ft_json_get_dict(value, "B"));
	out->c = ft_json_get_number(ft_json_get_dict(value, "C"));
	if (ft_json_dict_has_key(value, "D"))
		out->d = ft_json_get_number(ft_json_get_dict(value, "D"));
	if (ft_json_dict_has_key(value, "E"))
		out->e = ft_json_get_number(ft_json_get_dict(value, "E"));
	if (ft_json_dict_has_key(value, "F"))
		out->f = ft_json_get_number(ft_json_get_dict(value, "F"));
	if (ft_json_dict_has_key(value, "G"))
		out->g = ft_json_get_number(ft_json_get_dict(value, "G"));
	if (ft_json_dict_has_key(value, "H"))
		out->h = ft_json_get_number(ft_json_get_dict(value, "H"));
	if (ft_json_dict_has_key(value, "I"))
		out->i = ft_json_get_number(ft_json_get_dict(value, "I"));
	if (ft_json_dict_has_key(value, "J"))
		out->j = ft_json_get_number(ft_json_get_dict(value, "J"));
}

t_err	t_map_parse_quadric(t_ft_json value, t_map_quadric *out)
{
	if (ft_json_is_list(ft_json_get_dict(value, "properties")))
		list(ft_json_get_dict(value, "properties"), out);
	else
		dict(ft_json_get_dict(value, "properties"), out);
	t_map_parse_color_material(
		ft_json_get_dict(value, "material"), &out->material);
	return (t_map_parse_optional_limit(value, &out->limit));
}
