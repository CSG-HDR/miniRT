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

#include "fto_va_va_list.h"

#include "wrap.h"
#include "fto_va_va_list_v.h"

static const t_fto_va_va_list_vtable	g_v = {
	fto_va_va_list_v_free,
	fto_va_va_list_v_get_char,
	fto_va_va_list_v_get_signed_char,
	fto_va_va_list_v_get_signed_short,
	fto_va_va_list_v_get_signed_int,
	fto_va_va_list_v_get_signed_long,
	fto_va_va_list_v_get_signed_long_long,
	fto_va_va_list_v_get_unsigned_char,
	fto_va_va_list_v_get_unsigned_short,
	fto_va_va_list_v_get_unsigned_int,
	fto_va_va_list_v_get_unsigned_long,
	fto_va_va_list_v_get_unsigned_long_long,
	fto_va_va_list_v_get_float,
	fto_va_va_list_v_get_double,
	fto_va_va_list_v_get_long_double,
	fto_va_va_list_v_get_intmax_t,
	fto_va_va_list_v_get_uintmax_t,
	fto_va_va_list_v_get_ssize_t,
	fto_va_va_list_v_get_size_t,
	fto_va_va_list_v_get_ptrdiff_t,
	fto_va_va_list_v_get_pointer,
	fto_va_va_list_v_clone,
};

static t_fto_va_va_list	*new_shared(va_list *args)
{
	t_fto_va_va_list *const	result = wrap_malloc(sizeof(t_fto_va_va_list));

	if (!result)
		return (NULL);
	result->v.v = &g_v;
	result->args = args;
	result->va_list_owned = false;
	return (result);
}

static t_fto_va_va_list	*new_owned(va_list *args)
{
	t_fto_va_va_list_in *const	result
		= wrap_malloc(sizeof(t_fto_va_va_list_in));

	if (!result)
		return (NULL);
	va_copy(result->owned.args, *args);
	result->owned.list.v.v = &g_v;
	result->owned.list.args = &result->owned.args;
	result->owned.list.va_list_owned = true;
	return (&result->owned.list);
}

t_fto_va_va_list	*new_fto_va_va_list(va_list *args, bool va_list_owned)
{
	if (va_list_owned)
		return (new_shared(args));
	else
		return (new_owned(args));
}
