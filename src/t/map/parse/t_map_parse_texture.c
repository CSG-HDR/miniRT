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

#include "ft_cstring.h"
#include "t_map_parse.h"

#include "ft_json.h"
#include "t_map.h"

t_err	t_map_parse_texture(t_ft_json value, t_map_texture *out)
{
	if (ft_cstring_duplicate(ft_json_get_string(
				ft_json_get_dict(value, "src")), &out->src))
		return (true);
	out->width = ft_json_get_number(
			ft_json_get_list(ft_json_get_dict(value, "size"), 0));
	out->height = ft_json_get_number(
			ft_json_get_list(ft_json_get_dict(value, "size"), 1));
	out->nearest = (ft_json_dict_has_key(value, "nearest")
			&& ft_json_get_bool(ft_json_get_dict(value, "nearest")));
	out->mirror = (ft_json_dict_has_key(value, "mirror")
			&& ft_json_get_bool(ft_json_get_dict(value, "mirror")));
	return (false);
}
