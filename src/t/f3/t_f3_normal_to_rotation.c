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

t_f3	t_f3_normal_to_rotation(t_f3 normal)
{
	const t_f	pitch = t_f_atan2(normal.z, normal.y);
	const t_f	yaw = t_f_atan2(normal.x, normal.y);

	return ((t_f3){yaw, pitch, 0});
}
