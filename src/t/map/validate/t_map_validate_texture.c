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

bool	t_map_validate_texture(t_ft_json value)
{
	return (
		true
		&& t_map_validate_has_type(value, "texture")
		&& ft_json_dict_has_key(value, "src")
		&& ft_json_is_string(ft_json_get_dict(value, "src"))
		&& ft_json_dict_has_key(value, "size")
		&& ft_json_is_list(ft_json_get_dict(value, "size"))
		&& ft_json_list_length(ft_json_get_dict(value, "size")) == 2
		&& ft_json_is_number(
			ft_json_get_list(ft_json_get_dict(value, "size"), 0))
		&& ft_json_get_number(
			ft_json_get_list(ft_json_get_dict(value, "size"), 0)) > 0
		&& ft_json_is_number(
			ft_json_get_list(ft_json_get_dict(value, "size"), 1))
		&& ft_json_get_number(
			ft_json_get_list(ft_json_get_dict(value, "size"), 1)) > 0
		&& (!ft_json_dict_has_key(value, "nearest")
			|| ft_json_is_boolean(ft_json_get_dict(value, "nearest")))
		&& (!ft_json_dict_has_key(value, "mirror")
			|| ft_json_is_boolean(ft_json_get_dict(value, "mirror")))
	);
}
