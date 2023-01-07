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

#include "wrap.h"
#include "fto_stream_in_v.h"

static const struct s_fto_stream_buffered_in_vtable	g_v = {
	&fto_stream_buffered_in_v_read_all,
	&fto_stream_buffered_in_v_read_all,
	&fto_stream_buffered_in_v_end,
	&fto_stream_buffered_in_v_free
};

t_fto_stream_buffered_in	*new_fto_stream_buffered_in(
	t_fto_stream_in *stream,
	bool stream_owned,
	size_t buffer_capacity
)
{
	t_fto_stream_buffered_in *const	result
		= wrap_malloc(sizeof(t_fto_stream_buffered_in) + buffer_capacity);

	if (!result)
	{
		if (stream_owned)
			stream->v->free(stream);
		return (NULL);
	}
	result->v.v = &g_v;
	result->stream = stream;
	result->stream_owned = stream_owned;
	result->buffer_capacity = buffer_capacity;
	result->buffer_size = 0;
	result->buffer_offset = 0;
	return (result);
}
