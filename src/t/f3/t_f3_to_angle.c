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

#include "t_f.h"

t_f3	t_f3_to_angle(t_f3 normal)
{
	const t_f3	up = (t_f3){(t_f)0, (t_f)1, (t_f)0};
	const t_f3	right = t_f3_unit(t_f3_cross(normal, up));

	return ((t_f3){
		0,
		0,
		t_f_asin(right.x),
	});
}
