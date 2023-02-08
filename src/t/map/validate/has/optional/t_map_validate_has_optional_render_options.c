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

#include <stddef.h>
#include <stdbool.h>

#include "ft_json.h"

static bool	valid_super_sampling(t_ft_json value)
{
	return (
		true
		&& ft_json_is_number(value)
		&& (size_t)ft_json_get_number(value) == ft_json_get_number(value)
		&& (size_t)ft_json_get_number(value)
	);
}

static bool	valid_non_negative(t_ft_json value)
{
	return (
		true
		&& ft_json_is_number(value)
		&& ft_json_get_number(value) > 0
	);
}

static bool	valid_render_options(t_ft_json value)
{
	return (
		true
		&& ft_json_is_dict(value)
		&& (!ft_json_dict_has_key(value, "superSampling")
			|| valid_super_sampling(ft_json_get_dict(value, "superSampling")))
		&& (!ft_json_dict_has_key(value, "shadow")
			|| ft_json_is_boolean(ft_json_get_dict(value, "shadow")))
		&& (!ft_json_dict_has_key(value, "gamma")
			|| valid_non_negative(ft_json_get_dict(value, "gamma")))
		&& (!ft_json_dict_has_key(value, "exposure")
			|| valid_non_negative(ft_json_get_dict(value, "exposure")))
	);
}

bool	t_map_validate_has_optional_render_options(t_ft_json value)
{
	return (
		true
		&& ft_json_is_dict(value)
		&& (
			!ft_json_dict_has_key(value, "renderOptions")
			|| valid_render_options(ft_json_get_dict(value, "renderOptions"))
		)
	);
}
