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

#include "ft_stringbuilder.h"
#include "fto_stream_string_out_v.h"

#include "wrap.h"
#include "fto_stream_out_v.h"

static const struct s_fto_stream_string_out_vtable	g_v = {
	&fto_stream_string_out_v_write,
	(t_fto_stream_string_out_v_flush)(&fto_stream_out_v_flush),
	(t_fto_stream_string_out_v_try_free)(&fto_stream_out_v_try_free),
	&fto_stream_string_out_v_free_without_flush,
	&fto_stream_string_out_v_to_string,
};

t_fto_stream_string_out	*new_fto_stream_string_out(size_t buffer_size)
{
	t_fto_stream_string_out *const	result
		= wrap_malloc(sizeof(t_fto_stream_string_out));
	t_stringbuilder *const			stringbuilder
		= new_stringbuilder(buffer_size);

	if (!result || !stringbuilder)
	{
		wrap_free(result);
		if (stringbuilder)
			stringbuilder_free(stringbuilder);
		return (NULL);
	}
	result->v.v = &g_v;
	result->stringbuilder = stringbuilder;
	return (result);
}
