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

#ifndef FTO_VA_VA_LIST_H
# define FTO_VA_VA_LIST_H

# include "fto_va.h"

# include <stdbool.h>
# include <stdarg.h>

# include "ft_types.h"

union u_fto_va_va_list_vtable
{
	const struct s_fto_va_va_list_vtable	*v;
	const t_fto_va_vtable					*s;
};

typedef struct s_fto_va_va_list
{
	union u_fto_va_va_list_vtable	v;
	va_list							*args;
	bool							va_list_owned;
}	t_fto_va_va_list;

typedef void					(*t_fto_va_va_list_v_free)(
									t_fto_va_va_list *self);
typedef char					(*t_fto_va_va_list_v_get_char)(
									t_fto_va_va_list *self);
typedef signed char				(*t_fto_va_va_list_v_get_signed_char)(
									t_fto_va_va_list *self);
typedef signed short int		(*t_fto_va_va_list_v_get_signed_short)(
									t_fto_va_va_list *self);
typedef signed int				(*t_fto_va_va_list_v_get_signed_int)(
									t_fto_va_va_list *self);
typedef signed long int			(*t_fto_va_va_list_v_get_signed_long)(
									t_fto_va_va_list *self);
typedef signed long long int	(*t_fto_va_va_list_v_get_signed_long_long)(
									t_fto_va_va_list *self);
typedef unsigned char			(*t_fto_va_va_list_v_get_unsigned_char)(
									t_fto_va_va_list *self);
typedef unsigned short int		(*t_fto_va_va_list_v_get_unsigned_short)(
									t_fto_va_va_list *self);
typedef unsigned int			(*t_fto_va_va_list_v_get_unsigned_int)(
									t_fto_va_va_list *self);
typedef unsigned long int		(*t_fto_va_va_list_v_get_unsigned_long)(
									t_fto_va_va_list *self);
typedef unsigned long long		(*t_fto_va_va_list_v_get_unsigned_long_long)(
									t_fto_va_va_list *self);
typedef float					(*t_fto_va_va_list_v_get_float)(
									t_fto_va_va_list *self);
typedef double					(*t_fto_va_va_list_v_get_double)(
									t_fto_va_va_list *self);
typedef long double				(*t_fto_va_va_list_v_get_long_double)(
									t_fto_va_va_list *self);
typedef intmax_t				(*t_fto_va_va_list_v_get_intmax_t)(
									t_fto_va_va_list *self);
typedef uintmax_t				(*t_fto_va_va_list_v_get_uintmax_t)(
									t_fto_va_va_list *self);
typedef ssize_t					(*t_fto_va_va_list_v_get_ssize_t)(
									t_fto_va_va_list *self);
typedef size_t					(*t_fto_va_va_list_v_get_size_t)(
									t_fto_va_va_list *self);
typedef ptrdiff_t				(*t_fto_va_va_list_v_get_ptrdiff_t)(
									t_fto_va_va_list *self);
typedef void					*(*t_fto_va_va_list_v_get_pointer)(
									t_fto_va_va_list *self);
typedef t_fto_va_va_list		*(*t_fto_va_va_list_v_clone)(
										t_fto_va_va_list *self);

typedef struct s_fto_va_va_list_vtable
{
	t_fto_va_va_list_v_free							free;
	t_fto_va_va_list_v_get_char						get_char;
	t_fto_va_va_list_v_get_signed_char				get_signed_char;
	t_fto_va_va_list_v_get_signed_short				get_signed_short;
	t_fto_va_va_list_v_get_signed_int				get_signed_int;
	t_fto_va_va_list_v_get_signed_long				get_signed_long;
	t_fto_va_va_list_v_get_signed_long_long			get_signed_long_long;
	t_fto_va_va_list_v_get_unsigned_char			get_unsigned_char;
	t_fto_va_va_list_v_get_unsigned_short			get_unsigned_short;
	t_fto_va_va_list_v_get_unsigned_int				get_unsigned_int;
	t_fto_va_va_list_v_get_unsigned_long			get_unsigned_long;
	t_fto_va_va_list_v_get_unsigned_long_long		get_unsigned_long_long;
	t_fto_va_va_list_v_get_float					get_float;
	t_fto_va_va_list_v_get_double					get_double;
	t_fto_va_va_list_v_get_long_double				get_long_double;
	t_fto_va_va_list_v_get_intmax_t					get_intmax_t;
	t_fto_va_va_list_v_get_uintmax_t				get_uintmax_t;
	t_fto_va_va_list_v_get_ssize_t					get_ssize_t;
	t_fto_va_va_list_v_get_size_t					get_size_t;
	t_fto_va_va_list_v_get_ptrdiff_t				get_ptrdiff_t;
	t_fto_va_va_list_v_get_pointer					get_pointer;
	t_fto_va_va_list_v_clone						clone;
}	t_fto_va_va_list_vtable;

t_fto_va_va_list	*new_fto_va_va_list(va_list *args, bool va_list_owned);

#endif
