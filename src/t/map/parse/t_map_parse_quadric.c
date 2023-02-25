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

static void	dict_a_to_f(t_ft_json value, t_map_quadric *out)
{
	out->a = 0;
	if (ft_json_dict_has_key(value, "A"))
		out->a = ft_json_get_number(ft_json_get_dict(value, "A"));
	out->b = 0;
	if (ft_json_dict_has_key(value, "B"))
		out->b = ft_json_get_number(ft_json_get_dict(value, "B"));
	out->c = 0;
	if (ft_json_dict_has_key(value, "C"))
		out->c = ft_json_get_number(ft_json_get_dict(value, "C"));
	out->d = 0;
	if (ft_json_dict_has_key(value, "D"))
		out->d = ft_json_get_number(ft_json_get_dict(value, "D"));
	out->e = 0;
	if (ft_json_dict_has_key(value, "E"))
		out->e = ft_json_get_number(ft_json_get_dict(value, "E"));
	out->f = 0;
	if (ft_json_dict_has_key(value, "F"))
		out->f = ft_json_get_number(ft_json_get_dict(value, "F"));
}

static void	dict(t_ft_json value, t_map_quadric *out)
{
	dict_a_to_f(value, out);
	out->g = 0;
	if (ft_json_dict_has_key(value, "G"))
		out->g = ft_json_get_number(ft_json_get_dict(value, "G"));
	out->h = 0;
	if (ft_json_dict_has_key(value, "H"))
		out->h = ft_json_get_number(ft_json_get_dict(value, "H"));
	out->i = 0;
	if (ft_json_dict_has_key(value, "I"))
		out->i = ft_json_get_number(ft_json_get_dict(value, "I"));
	out->j = 0;
	if (ft_json_dict_has_key(value, "J"))
		out->j = ft_json_get_number(ft_json_get_dict(value, "J"));
}

void	t_map_parse_quadric(t_ft_json value, t_map_quadric *out)
{
	if (ft_json_is_list(ft_json_get_dict(value, "properties")))
		list(ft_json_get_dict(value, "properties"), out);
	else
		dict(ft_json_get_dict(value, "properties"), out);
	t_map_parse_get_optional_color_material(value, &out->material);
}
