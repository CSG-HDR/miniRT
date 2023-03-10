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

#include "t_f.h"
#include "t_f3.h"
#include "t_map.h"

void	t_map_parse_get_default_color_material(t_map_color_material *out)
{
	out->ambient = (t_f3){(t_f)1, (t_f)1, (t_f)1};
	out->diffuse = (t_f3){(t_f)1, (t_f)1, (t_f)1};
	out->specular = (t_f3){(t_f)1, (t_f)1, (t_f)1};
	out->specular_lobe = (t_f)1;
}
