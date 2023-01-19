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

#include "ft_cstring.h"
#include "ft_json.h"

bool	t_map_validate_difference(t_ft_json value)
{
	return (
		true
		&& ft_json_is_dict(value)
		&& ft_json_dict_has_key(value, "type")
		&& ft_json_is_string(ft_json_get_dict(value, "type"))
		&& ft_cstring_equals(
			ft_json_get_string(ft_json_get_dict(value, "type")), "difference")
		&& ft_json_dict_has_key(value, "from")
		&& t_map_validate_model(ft_json_get_dict(value, "from"))
		&& ft_json_dict_has_key(value, "subtract")
		&& t_map_validate_model(ft_json_get_dict(value, "subtract"))
	);
}
