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
#include "t_f3x3.h"

#include "t_f3.h"

static t_f3x3	rotate_yaw(t_f rad)
{
	const t_f3	x = {
		t_f_cos(rad),
		t_f_sin(rad),
		0,
	};
	const t_f3	y = {
		-t_f_sin(rad),
		t_f_cos(rad),
		0,
	};
	const t_f3	z = {
		0,
		0,
		1,
	};

	return ((t_f3x3){x, y, z});
}

static t_f3x3	rotate_pitch(t_f rad)
{
	const t_f3	x = {
		1,
		0,
		0,
	};
	const t_f3	y = {
		0,
		t_f_cos(rad),
		-t_f_sin(rad),
	};
	const t_f3	z = {
		0,
		t_f_sin(rad),
		t_f_cos(rad),
	};

	return ((t_f3x3){x, y, z});
}

static t_f3x3	rotate_roll(t_f rad)
{
	const t_f3	x = {
		t_f_cos(rad),
		0,
		t_f_sin(rad),
	};
	const t_f3	y = {
		0,
		1,
		0,
	};
	const t_f3	z = {
		-t_f_sin(rad),
		0,
		t_f_cos(rad),
	};

	return ((t_f3x3){x, y, z});
}

t_f3x3	t_f3x3_rotate(t_f yaw, t_f pitch, t_f roll)
{
	const t_f3x3	mat_yaw = rotate_yaw(yaw);
	const t_f3x3	mat_pitch = rotate_pitch(pitch);
	const t_f3x3	mat_roll = rotate_roll(roll);

	return (t_f3x3_mul(t_f3x3_mul(mat_roll, mat_pitch), mat_yaw));
}
