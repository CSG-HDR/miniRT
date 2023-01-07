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

t_err	fto_unwinder_list_v_add_failed_to_alloc(
	t_fto_unwinder_list *self,
	void **destination,
	void *value,
	void (*how_to_remove_value)(void *value)
)
{
	(void)self;
	how_to_remove_value(value);
	*destination = NULL;
	return (true);
}
