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

#include <math.h>

#include "ft_memory.h"
#include "t_f.h"

// TODO: norm, test

static void	multi_matirix(
	const t_f mat1[3][3],
	const t_f mat2[3][3],
	const t_f mat3[3][3],
	t_f ret_mat[3][3]
)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
		{
			k = -1;
			while (++k < 3)
				ret_mat[i][j] += mat1[i][k] * mat2[k][j];
		}
	}
	while (++i < 7)
	{
		j = -1;
		while (++j < 3)
		{
			k = -1;
			while (++k < 3)
				ret_mat[i - 4][j] += ret_mat[i - 4][k] * mat3[k][j];
		}
	}
}

static void	get_normal(t_f rotate_matrix[3][3], t_f3 *normal)
{
	t_f		temp[3];
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < 3)
	{
		temp[i] = (t_f)0;
		j = -1;
		while (++j < 3)
			temp[i] += rotate_matrix[i][j] * temp[j];
	}
	normal->x = temp[0];
	normal->y = temp[1];
	normal->z = temp[2];
}

t_f3	t_f3_rotate_to_normal(t_f3 rotate)
{
	const t_f	yaw = 2 * M_PI * rotate.x;
	const t_f	pitch = 2 * M_PI * rotate.y;
	const t_f	roll = 2 * M_PI * rotate.z;
	const t_f	matrix_yaw[3][3] = {
		{ t_f_cos(yaw), -t_f_sin(yaw), 0 },
		{ t_f_sin(yaw), t_f_cos(yaw), 0 },
		{ 0, 0, 1 }
	};
	const t_f	matrix_pitch[3][3] = {
		{ t_f_cos(pitch), 0, t_f_sin(pitch) },
		{ 0, 1, 0 },
		{ -t_f_sin(pitch), 0, t_f_cos(pitch) }
	};
	const t_f	matrix_roll[3][3] = {
		{ 1, 0, 0 },
		{ 0, t_f_cos(roll), -t_f_sin(roll) },
		{ 0, t_f_sin(roll), t_f_cos(roll) }
	};
	t_f	rotate_matrix[3][3];
	t_f3 normal;

	ft_memory_set(rotate_matrix, 0, sizeof(rotate_matrix));
	multi_matirix(matrix_yaw, matrix_pitch, matrix_roll, rotate_matrix);
	get_normal(rotate_matrix, &normal);
	return (normal);
}
