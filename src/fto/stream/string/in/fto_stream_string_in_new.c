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
#include "fto_stream_string_in_v.h"

#include "wrap.h"
#include "fto_stream_in_v.h"

static const struct s_fto_stream_string_in_vtable	g_v = {
	&fto_stream_string_in_v_read_all,
	&fto_stream_string_in_v_read_all,
	&fto_stream_string_in_v_end,
	&fto_stream_string_in_v_free,
	&fto_stream_string_in_v_reset,
};

t_fto_stream_string_in	*new_fto_stream_string_in(
	const char *string,
	bool string_owned
)
{
	t_fto_stream_string_in *const	result
		= wrap_malloc(sizeof(t_fto_stream_string_in));

	if (!result)
	{
		if (string_owned)
			wrap_free((void *)string);
		return (NULL);
	}
	result->v.v = &g_v;
	result->string = string;
	result->string_owned = string_owned;
	result->offset = 0;
	return (result);
}
