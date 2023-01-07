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

#include "fto_stream_string_out_v.h"

t_err	fto_stream_string_out_v_write(
	t_fto_stream_string_out *self,
	const char *buffer,
	size_t length,
	size_t *wrote_bytes
)
{
	*wrote_bytes = 0;
	if (stringbuilder_append(self->stringbuilder, length, buffer))
		return (true);
	*wrote_bytes = length;
	return (true);
}
