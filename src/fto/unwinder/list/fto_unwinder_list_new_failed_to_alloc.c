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

static const t_fto_unwinder_list_vtable	g_v = {
	fto_unwinder_list_v_end_ok_failed_to_alloc,
	fto_unwinder_list_v_end_error_failed_to_alloc,
	fto_unwinder_list_v_add_failed_to_alloc,
	fto_unwinder_list_v_add_failed_to_alloc,
};

static const t_fto_unwinder_list		g_o = {{&g_v}, NULL};

t_fto_unwinder_list	*fto_unwinder_list_new_failed_to_alloc(void)
{
	return ((t_fto_unwinder_list *)&g_o);
}
