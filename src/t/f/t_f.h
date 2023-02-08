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

#ifndef T_F_H
# define T_F_H

# ifndef PRECISION
#  define PRECISION 3
# endif

# if PRECISION == 0
#  define T_F_EPSILON 0.0078125

typedef long double	t_f;

# elif PRECISION == 1
#  define T_F_EPSILON 0.0078125

typedef double		t_f;

# elif PRECISION == 2
#  define T_F_EPSILON 0.0625

typedef float		t_f;

# elif PRECISION == 3
#  define T_F_EPSILON 0.125

typedef _Float16	t_f;

# endif

t_f	t_f_sqr(t_f f);
t_f	t_f_sqrt(t_f f);
// rotation(0~1) to radian
t_f	t_f_rad(t_f f);
// radian to rotation(0~1)
t_f	t_f_rot(t_f f);
t_f	t_f_abs(t_f f);
t_f	t_f_exp(t_f f);
t_f	t_f_pow(t_f a, t_f b);
t_f	t_f_max(t_f a, t_f b);
t_f	t_f_min(t_f a, t_f b);

t_f	t_f_sin(t_f f);
t_f	t_f_cos(t_f f);
t_f	t_f_tan(t_f f);
t_f	t_f_cot(t_f f);
t_f	t_f_sec(t_f f);
t_f	t_f_csc(t_f f);
t_f	t_f_sinh(t_f f);
t_f	t_f_cosh(t_f f);
t_f	t_f_tanh(t_f f);
t_f	t_f_coth(t_f f);
t_f	t_f_sech(t_f f);
t_f	t_f_csch(t_f f);
t_f	t_f_asin(t_f f);
t_f	t_f_acos(t_f f);
t_f	t_f_atan(t_f f);
t_f	t_f_atan2(t_f y, t_f x);
t_f	t_f_acot(t_f f);
t_f	t_f_asec(t_f f);
t_f	t_f_acsc(t_f f);
t_f	t_f_asinh(t_f f);
t_f	t_f_acosh(t_f f);
t_f	t_f_atanh(t_f f);
t_f	t_f_acoth(t_f f);
t_f	t_f_asech(t_f f);
t_f	t_f_acsch(t_f f);

#endif
