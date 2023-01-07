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

t_err	fto_stream_fd_in_v_read_all(
	t_fto_stream_fd_in *self,
	char *buffer,
	size_t length,
	size_t *read_bytes
)
{
	ssize_t	read_result;

	*read_bytes = 0;
	while (!self->end && *read_bytes != length)
	{
		read_result = wrap_read(self->fd, buffer, length - *read_bytes);
		if (read_result < 0)
			return (true);
		if (read_result == 0)
			self->end = true;
		*read_bytes += read_result;
	}
	return (false);
}
