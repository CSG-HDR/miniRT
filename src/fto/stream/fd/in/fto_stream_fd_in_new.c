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

#include "fto_stream_fd_in_v.h"

#include "wrap.h"

static const struct s_fto_stream_fd_in_vtable	g_v = {
	&fto_stream_fd_in_v_read,
	&fto_stream_fd_in_v_read_all,
	&fto_stream_fd_in_v_end,
	&fto_stream_fd_in_v_free,
};

t_fto_stream_fd_in	*new_fto_stream_fd_in(int fd, bool fd_owned)
{
	t_fto_stream_fd_in *const	result
		= wrap_malloc(sizeof(t_fto_stream_fd_in));

	if (!result)
	{
		if (fd_owned)
			wrap_close(fd);
		return (NULL);
	}
	result->v.v = &g_v;
	result->fd = fd;
	result->fd_owned = fd_owned;
	result->end = false;
	return (result);
}
