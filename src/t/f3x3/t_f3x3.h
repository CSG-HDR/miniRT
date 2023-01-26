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

#ifndef T_F3X3_H
# define T_F3X3_H

# include "t_f3.h"

typedef struct s_f3x3
{
	t_f3	x;
	t_f3	y;
	t_f3	z;
}	t_f3x3;

t_f3	t_f3x3_col_x(t_f3x3 mat);
t_f3	t_f3x3_col_y(t_f3x3 mat);
t_f3	t_f3x3_col_z(t_f3x3 mat);
t_f3x3	t_f3x3_mul(t_f3x3 a, t_f3x3 b);
t_f3x3	t_f3x3_t(t_f3x3 mat);
t_f3x3	t_f3x3_rotate(t_f yaw, t_f pitch, t_f roll);
t_f3	t_f3x3_mul_f3x3_f3(t_f3x3 mat, t_f3 vec);
t_f3	t_f3x3_mul_f3_f3x3(t_f3 vec, t_f3x3 mat);

#endif
