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

t_f3	t_color_get_multiply(
	const t_context *context,
	t_map_blend_multiply multiply,
	t_f x,
	t_f y
)
{
	t_f3	accumulator;
	size_t	i;

	accumulator = (t_f3){(t_f)1, (t_f)1, (t_f)1};
	i = -1;
	while (++i < multiply.children_count)
		accumulator
			= t_f3_mul3(
				accumulator,
				t_color_get(context, multiply.children[i], x, y));
	return (t_f3_min((t_f3){(t_f)1, (t_f)1, (t_f)1}, accumulator));
}
