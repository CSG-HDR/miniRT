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

#include "ft_os_file.h"

#include <fcntl.h>

#include "ft_stringbuilder.h"
#include "wrap.h"

#define BUFFER_SIZE 1024

static void	notify_length(t_stringbuilder *sb, size_t *out_length)
{
	if (out_length)
		*out_length = sb->length;
}

char	*ft_os_file_read(const char *filename, size_t *out_length)
{
	const int				fd = wrap_open(filename, O_RDONLY);
	t_stringbuilder *const	sb = new_stringbuilder(BUFFER_SIZE);
	char					buf[BUFFER_SIZE];
	ssize_t					bytes_read;
	char					*result;

	if (fd < 0 && sb)
		stringbuilder_free(sb);
	if (!sb && fd >= 0)
		wrap_close(fd);
	if (!sb || fd < 0)
		return (NULL);
	bytes_read = wrap_read(fd, buf, BUFFER_SIZE);
	while (bytes_read)
	{
		if (bytes_read < 0 || stringbuilder_append(sb, bytes_read, buf))
			return (stringbuilder_free(sb), wrap_close(fd), NULL);
		bytes_read = wrap_read(fd, buf, BUFFER_SIZE);
	}
	result = stringbuilder_to_string(sb, 0);
	notify_length(sb, out_length);
	stringbuilder_free(sb);
	wrap_close(fd);
	return (result);
}
