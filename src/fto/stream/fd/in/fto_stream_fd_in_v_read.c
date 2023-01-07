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

t_err	fto_stream_fd_in_v_read(
	t_fto_stream_fd_in *self,
	char *buffer,
	size_t length,
	size_t *read_bytes
)
{
	const ssize_t	result = wrap_read(self->fd, buffer, length);

	if (result < 0)
		return (true);
	*read_bytes = (size_t)result;
	if (result == 0)
		self->end = true;
	return (false);
}
