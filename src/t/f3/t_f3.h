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

#ifndef T_F3_H
# define T_F3_H

# include "t_f.h"

typedef struct s_f3
{
	t_f	x;
	t_f	y;
	t_f	z;
}	t_f3;

t_f3	t_f3_add(t_f3 a, t_f3 b);
t_f3	t_f3_sub(t_f3 a, t_f3 b);
t_f3	t_f3_mul(t_f3 a, t_f b);
t_f3	t_f3_div(t_f3 a, t_f b);
t_f3	t_f3_mul3(t_f3 a, t_f3 b);
t_f3	t_f3_div3(t_f3 a, t_f3 b);
t_f		t_f3_dot(t_f3 a, t_f3 b);
t_f3	t_f3_cross(t_f3 a, t_f3 b);
t_f3	t_f3_min(t_f3 a, t_f3 b);
t_f3	t_f3_max(t_f3 a, t_f3 b);
t_f3	t_f3_neg(t_f3 f);
t_f3	t_f3_inv(t_f3 f);
t_f		t_f3_sqr_length(t_f3 f);
t_f		t_f3_length(t_f3 f);
t_f3	t_f3_unit(t_f3 f);
t_f3	t_f3_rotate(t_f3 point, t_f3 rotation);
t_f3	t_f3_rotate_reverse(t_f3 point, t_f3 rotation);
t_f3	t_f3_rotate_from_origin(t_f3 point, t_f3 origin, t_f3 rotation);
t_f3	t_f3_rotate_reverse_from_origin(t_f3 point, t_f3 origin, t_f3 rotation);
t_f3	t_f3_normal_to_rotation(t_f3 normal);

#endif
