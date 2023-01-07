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

#ifndef FTO_VA_VA_LIST_V_H
# define FTO_VA_VA_LIST_V_H

# include "fto_va_va_list.h"

typedef struct s_fto_va_va_list_owned
{
	t_fto_va_va_list	list;
	va_list				args;
}	t_fto_va_va_list_owned;

typedef union u_fto_va_va_list_in
{
	t_fto_va_va_list		shared;
	t_fto_va_va_list_owned	owned;
}	t_fto_va_va_list_in;

t_fto_va_va_list		*new_fto_va_va_list(va_list *args, bool va_list_owned);

void					fto_va_va_list_v_free(
							t_fto_va_va_list *self);
char					fto_va_va_list_v_get_char(
							t_fto_va_va_list *self);
signed char				fto_va_va_list_v_get_signed_char(
							t_fto_va_va_list *self);
signed short int		fto_va_va_list_v_get_signed_short(
							t_fto_va_va_list *self);
signed int				fto_va_va_list_v_get_signed_int(
							t_fto_va_va_list *self);
signed long int			fto_va_va_list_v_get_signed_long(
							t_fto_va_va_list *self);
signed long long int	fto_va_va_list_v_get_signed_long_long(
							t_fto_va_va_list *self);
unsigned char			fto_va_va_list_v_get_unsigned_char(
							t_fto_va_va_list *self);
unsigned short int		fto_va_va_list_v_get_unsigned_short(
							t_fto_va_va_list *self);
unsigned int			fto_va_va_list_v_get_unsigned_int(
							t_fto_va_va_list *self);
unsigned long int		fto_va_va_list_v_get_unsigned_long(
							t_fto_va_va_list *self);
unsigned long long		fto_va_va_list_v_get_unsigned_long_long(
							t_fto_va_va_list *self);
float					fto_va_va_list_v_get_float(
							t_fto_va_va_list *self);
double					fto_va_va_list_v_get_double(
							t_fto_va_va_list *self);
long double				fto_va_va_list_v_get_long_double(
							t_fto_va_va_list *self);
intmax_t				fto_va_va_list_v_get_intmax_t(
							t_fto_va_va_list *self);
uintmax_t				fto_va_va_list_v_get_uintmax_t(
							t_fto_va_va_list *self);
ssize_t					fto_va_va_list_v_get_ssize_t(
							t_fto_va_va_list *self);
size_t					fto_va_va_list_v_get_size_t(
							t_fto_va_va_list *self);
ptrdiff_t				fto_va_va_list_v_get_ptrdiff_t(
							t_fto_va_va_list *self);
void					*fto_va_va_list_v_get_pointer(
							t_fto_va_va_list *self);
t_fto_va_va_list		*fto_va_va_list_v_clone(
							t_fto_va_va_list *self);

#endif
