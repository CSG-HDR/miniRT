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

#include "t_f.h"
#include "t_f3.h"
#include "t_map.h"

#include "t.h"

t_map_material_color	t_color_get_to_ldr(
	const t_context *context,
	t_f3 color
)
{
	const t_map_material_color	mapped = {
		(t_f)1 - t_f_exp(-color.x * context->map->render_options.exposure),
		(t_f)1 - t_f_exp(-color.y * context->map->render_options.exposure),
		(t_f)1 - t_f_exp(-color.z * context->map->render_options.exposure),
	};
	const t_map_material_color	result = {
		t_f_pow(mapped.x, (t_f)1 / context->map->render_options.gamma),
		t_f_pow(mapped.y, (t_f)1 / context->map->render_options.gamma),
		t_f_pow(mapped.z, (t_f)1 / context->map->render_options.gamma),
	};

	return (result);
}
