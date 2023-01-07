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

#include "fto_unwinder_list_v.h"

#include <stdlib.h>

static const t_fto_unwinder_list_vtable	g_v = {
	fto_unwinder_list_v_end_ok,
	fto_unwinder_list_v_end_error,
	fto_unwinder_list_v_add,
	fto_unwinder_list_v_add_always
};

t_fto_unwinder_list	*fto_unwinder_list_new(void)
{
	t_fto_unwinder_list *const	result = malloc(sizeof(t_fto_unwinder_list));

	if (!result)
		return (fto_unwinder_list_new_failed_to_alloc());
	result->v.v = &g_v;
	result->head = NULL;
	return (result);
}
