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

void	t_map_free_color(t_map_color value)
{
	if (*value.type == T_MAP_COLOR_TYPE_COLOR)
	{
		wrap_free(value.color);
	}
	else
	{
		t_map_free_texture(value.texture->texture);
		wrap_free(value.texture);
	}
}
