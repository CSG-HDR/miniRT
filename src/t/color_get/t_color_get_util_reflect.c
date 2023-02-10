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

#include "t_f.h"
#include "t_f3.h"
#include "t_map.h"

t_f3	t_color_get_util_reflect(
	const t_map_normal incidence,
	const t_map_normal normal
)
{
	const t_map_normal	neg = t_f3_neg(normal);
	const t_f			length = t_f3_dot(neg, incidence);
	const t_f3			sum = t_f3_mul(t_f3_mul(neg, 2), length);
	const t_f3			neg_direction = t_f3_sub(sum, incidence);
	const t_map_normal	result = t_f3_neg(t_f3_unit(neg_direction));

	return (result);
}
