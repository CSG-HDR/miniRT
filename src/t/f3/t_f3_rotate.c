/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_f3_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2023/01/26 23:22:13 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_f3.h"

#include "t_f3x3.h"

t_f3	t_f3_rotate(t_f3 point, t_f3 rotation)
{
	const t_f	yaw = rotation.x;
	const t_f	pitch = rotation.y;
	const t_f	roll = rotation.z;

	return (t_f3x3_mul_f3_f3x3(point, t_f3x3_rotate(yaw, pitch, roll)));
}
