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

static void	list_4(t_ft_json value, t_map_quartic *out)
{
	out->c400 = ft_json_get_number(ft_json_get_list(value, 0));
	out->c040 = ft_json_get_number(ft_json_get_list(value, 1));
	out->c004 = ft_json_get_number(ft_json_get_list(value, 2));
	out->c310 = ft_json_get_number(ft_json_get_list(value, 3));
	out->c301 = ft_json_get_number(ft_json_get_list(value, 4));
	out->c130 = ft_json_get_number(ft_json_get_list(value, 5));
	out->c031 = ft_json_get_number(ft_json_get_list(value, 6));
	out->c103 = ft_json_get_number(ft_json_get_list(value, 7));
	out->c013 = ft_json_get_number(ft_json_get_list(value, 8));
	out->c220 = ft_json_get_number(ft_json_get_list(value, 9));
	out->c022 = ft_json_get_number(ft_json_get_list(value, 10));
	out->c202 = ft_json_get_number(ft_json_get_list(value, 11));
	out->c211 = ft_json_get_number(ft_json_get_list(value, 12));
	out->c121 = ft_json_get_number(ft_json_get_list(value, 13));
	out->c112 = ft_json_get_number(ft_json_get_list(value, 14));
}

static void	list(t_ft_json value, t_map_quartic *out)
{
	list_4(value, out);
	out->c300 = ft_json_get_number(ft_json_get_list(value, 15));
	out->c030 = ft_json_get_number(ft_json_get_list(value, 16));
	out->c003 = ft_json_get_number(ft_json_get_list(value, 17));
	out->c210 = ft_json_get_number(ft_json_get_list(value, 18));
	out->c201 = ft_json_get_number(ft_json_get_list(value, 19));
	out->c120 = ft_json_get_number(ft_json_get_list(value, 20));
	out->c021 = ft_json_get_number(ft_json_get_list(value, 21));
	out->c102 = ft_json_get_number(ft_json_get_list(value, 22));
	out->c012 = ft_json_get_number(ft_json_get_list(value, 23));
	out->c111 = ft_json_get_number(ft_json_get_list(value, 24));
	out->c200 = ft_json_get_number(ft_json_get_list(value, 25));
	out->c020 = ft_json_get_number(ft_json_get_list(value, 26));
	out->c002 = ft_json_get_number(ft_json_get_list(value, 27));
	out->c110 = ft_json_get_number(ft_json_get_list(value, 28));
	out->c011 = ft_json_get_number(ft_json_get_list(value, 29));
	out->c101 = ft_json_get_number(ft_json_get_list(value, 30));
	out->c100 = ft_json_get_number(ft_json_get_list(value, 31));
	out->c010 = ft_json_get_number(ft_json_get_list(value, 32));
	out->c001 = ft_json_get_number(ft_json_get_list(value, 33));
	out->c000 = ft_json_get_number(ft_json_get_list(value, 34));
}

void	t_map_parse_quartic(t_ft_json value, t_map_quartic *out)
{
	list(ft_json_get_dict(value, "coefficients"), out);
	t_map_parse_get_optional_color_material(value, &out->material);
}
