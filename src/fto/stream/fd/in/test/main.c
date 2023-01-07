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

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "fto_stream_fd_in.h"

#define BUFFER_SIZE 4

int	main(void)
{
	t_fto_stream_in *const	stream
		= (t_fto_stream_in *)new_fto_stream_fd_in(STDIN_FILENO, true);
	char					buffer[BUFFER_SIZE];
	size_t					bytes_read;

	if (!stream)
		return (EXIT_FAILURE);
	while (
		!stream->v->end(stream)
		&& !stream->v->read(stream, buffer, BUFFER_SIZE, &bytes_read)
	)
		fwrite(buffer, 1, bytes_read, stdout);
	if (!stream->v->end(stream))
		return (true);
	return (EXIT_SUCCESS);
}
