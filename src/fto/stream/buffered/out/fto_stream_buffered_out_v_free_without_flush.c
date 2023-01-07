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

void	fto_stream_buffered_out_v_free_without_flush(
	t_fto_stream_buffered_out *self
)
{
	if (self->stream_owned)
		self->stream->v->free_without_flush(self->stream);
	wrap_free(self);
}
