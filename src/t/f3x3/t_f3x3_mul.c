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

#include "t_f3x3.h"

#include "t_f3.h"

t_f3x3	t_f3x3_mul(t_f3x3 a, t_f3x3 b)
{
	const t_f3	x = {
		t_f3_dot(a.x, t_f3x3_col_x(b)),
		t_f3_dot(a.x, t_f3x3_col_y(b)),
		t_f3_dot(a.x, t_f3x3_col_z(b)),
	};
	const t_f3	y = {
		t_f3_dot(a.y, t_f3x3_col_x(b)),
		t_f3_dot(a.y, t_f3x3_col_y(b)),
		t_f3_dot(a.y, t_f3x3_col_z(b)),
	};
	const t_f3	z = {
		t_f3_dot(a.z, t_f3x3_col_x(b)),
		t_f3_dot(a.z, t_f3x3_col_y(b)),
		t_f3_dot(a.z, t_f3x3_col_z(b)),
	};

	return ((t_f3x3){x, y, z});
}
