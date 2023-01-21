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
#include "t_map_validate.h"

t_err	t_map_parse_blend(t_ft_json value, t_map_blend *out)
{
	if (t_map_validate_has_type(value, "add"))
		return (t_map_parse_blend_add(value, &out->add));
	if (t_map_validate_has_type(value, "multiply"))
		return (t_map_parse_blend_multiply(value, &out->multiply));
	if (t_map_validate_has_type(value, "maximum"))
		return (t_map_parse_blend_maximum(value, &out->maximum));
	if (t_map_validate_has_type(value, "minimum"))
		return (t_map_parse_blend_minimum(value, &out->minimum));
	else
		return (t_map_parse_blend_subtract(value, &out->subtract));
}
