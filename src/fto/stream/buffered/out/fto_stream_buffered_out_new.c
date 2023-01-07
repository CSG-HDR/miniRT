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

#include "wrap.h"
#include "fto_stream_out_v.h"

static const struct s_fto_stream_buffered_out_vtable	g_v = {
	&fto_stream_buffered_out_v_write,
	&fto_stream_buffered_out_v_flush,
	(t_fto_stream_buffered_out_v_try_free)(&fto_stream_out_v_try_free),
	&fto_stream_buffered_out_v_free_without_flush
};

t_fto_stream_buffered_out	*new_fto_stream_buffered_out(
	t_fto_stream_out *stream,
	bool stream_owned,
	size_t buffer_capacity
)
{
	t_fto_stream_buffered_out *const	result
		= wrap_malloc(sizeof(t_fto_stream_buffered_out) + buffer_capacity);

	if (!result)
	{
		if (stream_owned)
			stream->v->free_without_flush(stream);
		return (NULL);
	}
	result->v.v = &g_v;
	result->stream = stream;
	result->stream_owned = stream_owned;
	result->buffer_capacity = buffer_capacity;
	result->buffer_size = 0;
	return (result);
}
