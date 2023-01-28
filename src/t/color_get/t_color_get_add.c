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

t_f3	t_color_get_add(
	const t_context *context,
	t_map_blend_add add,
	t_f x,
	t_f y
)
{
	t_f3	accumulator;
	size_t	i;

	accumulator = (t_f3){(t_f)0, (t_f)0, (t_f)0};
	i = -1;
	while (++i < add.children_count)
		accumulator
			= t_f3_add(
				accumulator,
				t_color_get(context, add.children[i], x, y));
	return (t_f3_min((t_f3){(t_f)1, (t_f)1, (t_f)1}, accumulator));
}
