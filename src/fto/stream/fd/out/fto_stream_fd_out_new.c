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

#include "fto_stream_fd_out_v.h"

#include "wrap.h"

#include "fto_stream_out_v.h"

static const struct s_fto_stream_fd_out_vtable	g_v = {
	&fto_stream_fd_out_v_write,
	(t_fto_stream_fd_out_v_flush)(&fto_stream_out_v_flush),
	(t_fto_stream_fd_out_v_try_free)(&fto_stream_out_v_try_free),
	&fto_stream_fd_out_v_free_without_flush,
};

t_fto_stream_fd_out	*new_fto_stream_fd_out(int fd, bool fd_owned)
{
	t_fto_stream_fd_out *const	result
		= wrap_malloc(sizeof(t_fto_stream_fd_out));

	if (!result)
	{
		if (fd_owned)
			wrap_close(fd);
		return (NULL);
	}
	result->v.v = &g_v;
	result->fd = fd;
	result->fd_owned = fd_owned;
	return (result);
}
