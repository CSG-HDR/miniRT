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

#include "fto_va_va_list_v.h"

ptrdiff_t	fto_va_va_list_v_get_ptrdiff_t(
	t_fto_va_va_list *self
)
{
	if (sizeof(ptrdiff_t) < sizeof(int))
		return ((ptrdiff_t)va_arg(*self->args, int));
	else
		return (va_arg(*self->args, ptrdiff_t));
}
