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

#include "t_map_free.h"

#include "wrap.h"
#include "t_map.h"

void	t_map_free_light(t_map_light value)
{
	if (*value.type == T_MAP_LIGHT_TYPE_POINT)
		wrap_free(value.point);
	if (*value.type == T_MAP_LIGHT_TYPE_DIRECTIONAL)
		wrap_free(value.directional);
	else
		wrap_free(value.spot);
}
