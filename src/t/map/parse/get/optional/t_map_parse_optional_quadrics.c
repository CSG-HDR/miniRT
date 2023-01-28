/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_parse_optional_quadrics.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2023/01/28 23:32:46 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_map_parse.h"

#include <stddef.h>

#include "wrap.h"
#include "ft_json.h"
#include "t_map.h"

t_err	t_map_parse_get_optional_quadrics(
	t_ft_json value,
	t_map_quadric **out,
	size_t *out_count
)
{
	if (!ft_json_dict_has_key(value, "quadrics"))
	{
		*out_count = 0;
		return (false);
	}
	return (
		t_map_parse_quadrics(
			ft_json_get_dict(value, "quadrics"),
			out,
			out_count
		)
	);
}
