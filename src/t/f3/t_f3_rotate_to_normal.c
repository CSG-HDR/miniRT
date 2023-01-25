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
#include "string.h"

// TODO: norm, test

static	void multi_matirix(const t_f mat1[3][3], const t_f mat2[3][3],
							const t_f mat3[3][3], t_f ret_mat[3][3])
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                ret_mat[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                ret_mat[i][j] += ret_mat[i][k] * mat3[k][j];
            }
        }
    }
}

static	void get_normal(t_f rotate_matrix[3][3], t_f3 *normal)
{
	t_f	temp[3] = {0, 0, 1};

	for (int i = 0; i < 3; i++) {
        temp[i] = 0;
        for (int j = 0; j < 3; j++) {
            temp[i] += rotate_matrix[i][j] * temp[j];
        }
    };
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
	memset(rotate_matrix, 0, sizeof(rotate_matrix));
	multi_matirix(matrix_yaw, matrix_pitch, matrix_roll, rotate_matrix);
	get_normal(rotate_matrix, &normal);
	return (normal);
}
