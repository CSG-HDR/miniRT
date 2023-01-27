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

#include "t_f3.h"

#include "t_f3x3.h"

t_f3	t_f3_rotate_from_origin(t_f3 point, t_f3 origin, t_f3 rotation)
{
	const t_f3	point_minus_origin = t_f3_sub(point, origin);
	const t_f3	rotated = t_f3_rotate(point_minus_origin, rotation);
	const t_f3	result = t_f3_add(rotated, origin);

	return (result);
}
