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

#ifndef FTO_UNWINDER_LIST_V_H
# define FTO_UNWINDER_LIST_V_H

# include "fto_unwinder_list.h"

t_err				fto_unwinder_list_v_end_ok(
						t_fto_unwinder_list *self);
t_err				fto_unwinder_list_v_end_error(
						t_fto_unwinder_list *self);
t_err				fto_unwinder_list_v_add(
						t_fto_unwinder_list *self,
						void **destination,
						void *value,
						void (*how_to_remove_value)(void *value));
t_err				fto_unwinder_list_v_add_always(
						t_fto_unwinder_list *self,
						void **destination,
						void *value,
						void (*how_to_remove_value)(void *value));

t_err				fto_unwinder_list_v_end_ok_failed_to_alloc(
						t_fto_unwinder_list *self);
t_err				fto_unwinder_list_v_end_error_failed_to_alloc(
						t_fto_unwinder_list *self);
t_err				fto_unwinder_list_v_add_failed_to_alloc(
						t_fto_unwinder_list *self,
						void **destination,
						void *value,
						void (*how_to_remove_value)(void *value));

t_fto_unwinder_list	*fto_unwinder_list_new_failed_to_alloc(void);

#endif
