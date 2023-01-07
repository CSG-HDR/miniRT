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

#ifndef FTO_VA_H
# define FTO_VA_H

# include <stddef.h>
# include <stdint.h>
# include <unistd.h>

typedef struct s_fto_va
{
	const struct s_fto_va_vtable	*v;
}	t_fto_va;

typedef void					(*t_fto_va_v_free)(
									t_fto_va *self);
typedef char					(*t_fto_va_v_get_char)(
									t_fto_va *self);
typedef signed char				(*t_fto_va_v_get_signed_char)(
									t_fto_va *self);
typedef signed short int		(*t_fto_va_v_get_signed_short_int)(
									t_fto_va *self);
typedef signed int				(*t_fto_va_v_get_signed_int)(
									t_fto_va *self);
typedef signed long int			(*t_fto_va_v_get_signed_long_int)(
									t_fto_va *self);
typedef signed long long int	(*t_fto_va_v_get_signed_long_long_int)(
									t_fto_va *self);
typedef unsigned char			(*t_fto_va_v_get_unsigned_char)(
									t_fto_va *self);
typedef unsigned short int		(*t_fto_va_v_get_unsigned_short_int)(
									t_fto_va *self);
typedef unsigned int			(*t_fto_va_v_get_unsigned_int)(
									t_fto_va *self);
typedef unsigned long int		(*t_fto_va_v_get_unsigned_long_int)(
									t_fto_va *self);
typedef unsigned long long int	(*t_fto_va_v_get_unsigned_long_long_int)(
									t_fto_va *self);
typedef float					(*t_fto_va_v_get_float)(
									t_fto_va *self);
typedef double					(*t_fto_va_v_get_double)(
									t_fto_va *self);
typedef long double				(*t_fto_va_v_get_long_double)(
									t_fto_va *self);
typedef intmax_t				(*t_fto_va_v_get_intmax_t)(
									t_fto_va *self);
typedef uintmax_t				(*t_fto_va_v_get_uintmax_t)(
									t_fto_va *self);
typedef ssize_t					(*t_fto_va_v_get_ssize_t)(
									t_fto_va *self);
typedef size_t					(*t_fto_va_v_get_size_t)(
									t_fto_va *self);
typedef ptrdiff_t				(*t_fto_va_v_get_ptrdiff_t)(
									t_fto_va *self);
typedef void					*(*t_fto_va_v_get_pointer)(
									t_fto_va *self);

typedef struct s_fto_va_vtable
{
	t_fto_va_v_free							free;
	t_fto_va_v_get_char						get_char;
	t_fto_va_v_get_signed_char				get_signed_char;
	t_fto_va_v_get_signed_short_int			get_signed_short_int;
	t_fto_va_v_get_signed_int				get_signed_int;
	t_fto_va_v_get_signed_long_int			get_signed_long_int;
	t_fto_va_v_get_signed_long_long_int		get_signed_long_long_int;
	t_fto_va_v_get_unsigned_char			get_unsigned_char;
	t_fto_va_v_get_unsigned_short_int		get_unsigned_short_int;
	t_fto_va_v_get_unsigned_int				get_unsigned_int;
	t_fto_va_v_get_unsigned_long_int		get_unsigned_long_int;
	t_fto_va_v_get_unsigned_long_long_int	get_unsigned_long_long_int;
	t_fto_va_v_get_float					get_float;
	t_fto_va_v_get_double					get_double;
	t_fto_va_v_get_long_double				get_long_double;
	t_fto_va_v_get_intmax_t					get_intmax_t;
	t_fto_va_v_get_uintmax_t				get_uintmax_t;
	t_fto_va_v_get_ssize_t					get_ssize_t;
	t_fto_va_v_get_size_t					get_size_t;
	t_fto_va_v_get_ptrdiff_t				get_ptrdiff_t;
	t_fto_va_v_get_pointer					get_pointer;
}	t_fto_va_vtable;

#endif
