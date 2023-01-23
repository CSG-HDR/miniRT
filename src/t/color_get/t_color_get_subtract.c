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

#include "t_color_get.h"

#include "t.h"
#include "t_f3.h"
#include "t_map.h"

t_f3	t_color_get_subtract(
	t_context *context,
	t_map_blend_subtract subtract,
	t_f x,
	t_f y
)
{
	const t_f3	zero = {(t_f)0, (t_f)0, (t_f)0};

	return (
		t_f3_max(
			zero,
			t_f3_sub(
				t_color_get(context, subtract.from, x, y),
				t_color_get(context, subtract.subtract, x, y)
			)
		)
	);
}
