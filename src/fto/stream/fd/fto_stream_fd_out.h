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

#ifndef FTO_STREAM_FD_OUT_H
# define FTO_STREAM_FD_OUT_H

# include "fto_stream_out.h"

union u_fto_stream_fd_out_vtable
{
	const struct s_fto_stream_fd_out_vtable	*v;
	const t_fto_stream_out_vtable			*s;
};

typedef struct s_fto_stream_fd_out
{
	union u_fto_stream_fd_out_vtable	v;
	int									fd;
	bool								fd_owned;
}	t_fto_stream_fd_out;

typedef t_err	(*t_fto_stream_fd_out_v_write)(
					t_fto_stream_fd_out *self,
					const char *buffer,
					size_t length,
					size_t *wrote_bytes);
typedef t_err	(*t_fto_stream_fd_out_v_flush)(
					t_fto_stream_fd_out *self);
typedef t_err	(*t_fto_stream_fd_out_v_try_free)(
					t_fto_stream_fd_out *self);
typedef void	(*t_fto_stream_fd_out_v_free_without_flush)(
					t_fto_stream_fd_out *self);

struct s_fto_stream_fd_out_vtable
{
	t_fto_stream_fd_out_v_write					write;
	t_fto_stream_fd_out_v_flush					flush;
	t_fto_stream_fd_out_v_try_free				try_free;
	t_fto_stream_fd_out_v_free_without_flush	free_without_flush;
};

t_fto_stream_fd_out	*new_fto_stream_fd_out(int fd, bool fd_owned);

#endif
