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

#include "fto_stream_buffered_out_v.h"

t_err	fto_stream_buffered_out_v_flush(
	t_fto_stream_buffered_out *self
)
{
	size_t	wrote_bytes;
	t_err	result;

	result
		= (
			self->stream->v->write(
				self->stream,
				self->buffer,
				self->buffer_size,
				&wrote_bytes)
			|| wrote_bytes != self->buffer_size);
	self->buffer_size -= wrote_bytes;
	return (result || self->stream->v->flush(self->stream));
}
