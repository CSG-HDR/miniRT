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

static bool	valid_list(t_ft_json value)
{
	size_t	i;

	i = -1;
	while (++i < 35)
		if (!t_map_validate_has_number_list(value, i))
			return (false);
	return (true);
}

static bool	is_coefficients(t_ft_json value)
{
	if (ft_json_is_list(value))
		return (valid_list(value));
	return (false);
}

static bool	has_coefficients(t_ft_json value)
{
	return (
		true
		&& ft_json_is_dict(value)
		&& ft_json_dict_has_key(value, "coefficients")
		&& is_coefficients(ft_json_get_dict(value, "coefficients"))
	);
}

bool	t_map_validate_quartic(t_ft_json value)
{
	return (
		true
		&& has_coefficients(value)
		&& t_map_validate_has_optional_color_material(value)
	);
}
