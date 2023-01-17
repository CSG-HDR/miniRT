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

typedef long double	t_f;

# elif PRECISION == 1

typedef double		t_f;

# elif PRECISION == 2

typedef float		t_f;

# elif PRECISION == 3

typedef _Float16	t_f;

# endif

t_f	t_f_sqr(t_f f);
t_f	t_f_sqrt(t_f f);

#endif
