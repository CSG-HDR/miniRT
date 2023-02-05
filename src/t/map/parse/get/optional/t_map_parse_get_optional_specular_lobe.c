/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_parse_optional_specular_lobe.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2023/01/28 23:32:53 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_map_parse.h"

#include <stddef.h>

#include "ft_json.h"
#include "t_f.h"
#include "t_map.h"

void	t_map_parse_get_optional_specular_lobe(t_ft_json value, t_f *out)
{
	if (ft_json_dict_has_key(value, "specularLobe"))
		*out = ft_json_get_number(ft_json_get_dict(value, "specularLobe"));
	else
		*out = (t_f)1;
}
