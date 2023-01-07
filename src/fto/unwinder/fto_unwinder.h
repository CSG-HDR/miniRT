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

#ifndef FTO_UNWINDER_H
# define FTO_UNWINDER_H

# include "ft_types.h"

# include <stddef.h>

typedef struct s_fto_unwinder
{
	const struct s_fto_unwinder_vtable	*v;
}	t_fto_unwinder;

typedef t_err	(*t_fto_unwinder_v_end_ok)(
					t_fto_unwinder *self);
typedef t_err	(*t_fto_unwinder_v_end_error)(
					t_fto_unwinder *self);
typedef void	*(*t_fto_unwinder_v_add)(
					t_fto_unwinder *self,
					void *value,
					void (*how_to_remove_value)(void *value));
typedef void	*(*t_fto_unwinder_v_add_always)(
					t_fto_unwinder *self,
					void *value,
					void (*how_to_remove_value)(void *value));

typedef struct s_fto_unwinder_vtable
{
	t_fto_unwinder_v_end_ok		end_ok;
	t_fto_unwinder_v_end_error	end_error;
	t_fto_unwinder_v_add		add;
	t_fto_unwinder_v_add_always	add_always;
}	t_fto_unwinder_vtable;

#endif
