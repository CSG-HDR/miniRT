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

t_f3	t_f3_rotate(t_f3 point, t_f3 rotation)
{
	const t_f		yaw = rotation.x;
	const t_f		pitch = rotation.y;
	const t_f		roll = rotation.z;

	return (t_f3x3_mul_f3(t_f3x3_rotate(yaw, pitch, roll), point));
}
