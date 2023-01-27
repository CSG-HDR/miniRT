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

t_f3	t_f3_normal_to_rotation(t_f3 normal)
{
	// x-axis rotation : roll
	// y-axis rotation : pitch
	// z-axis rotaion : yaw
	const t_f	roll = t_f_atan2(normal.z, normal.y);
	const t_f	pitch = t_f_atan2(normal.z, normal.x);
	const t_f	yaw = t_f_atan2(normal.y, normal.x);
	return ((t_f3){yaw, pitch, roll});
}
