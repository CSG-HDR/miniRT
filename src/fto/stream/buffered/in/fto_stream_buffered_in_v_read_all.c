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

#include "fto_stream_buffered_in_v.h"

#include "ft_memory.h"
#include "ft_types_primitive_size_t.h"

static t_err	fill_buffer(
	t_fto_stream_buffered_in *self
)
{
	return (
		!self->buffer_offset
		&& self->stream->v->read(
			self->stream,
			self->buffer,
			self->buffer_capacity,
			&self->buffer_size
		)
	);
}

static size_t	feed(
	t_fto_stream_buffered_in *self,
	size_t limit,
	void *buffer
)
{
	const size_t	remain = self->buffer_size - self->buffer_offset;
	const size_t	to_feed = ft_types_primitive_size_t_max(remain, limit);

	ft_memory_copy(buffer, self->buffer + self->buffer_offset, to_feed);
	self->buffer_offset += to_feed;
	if (self->buffer_offset == self->buffer_size)
	{
		self->buffer_offset = 0;
		self->buffer_size = 0;
	}
	return (to_feed);
}

t_err	fto_stream_buffered_in_v_read_all(
	t_fto_stream_buffered_in *self,
	char *buffer,
	size_t length,
	size_t *read_bytes
)
{
	*read_bytes = 0;
	while (*read_bytes < length && !fto_stream_buffered_in_v_end(self))
	{
		if (fill_buffer(self))
			return (true);
		*read_bytes += feed(self, length - *read_bytes, buffer);
	}
	return (false);
}
