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

size_t	fto_va_va_list_v_get_size_t(
	t_fto_va_va_list *self
)
{
	if (sizeof(size_t) < sizeof(int))
		return ((size_t)va_arg(*self->args, unsigned int));
	else
		return (va_arg(*self->args, size_t));
}
