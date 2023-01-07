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

#include "fto_stream_string_in_v.h"

t_err	fto_stream_string_in_v_read_all(
	t_fto_stream_string_in *self,
	char *buffer,
	size_t length,
	size_t *read_bytes
)
{
	*read_bytes = 0;
	while (*read_bytes < length && self->string[self->offset])
	{
		buffer[*read_bytes] = self->string[self->offset];
		(*read_bytes)++;
		self->offset++;
	}
	return (false);
}
