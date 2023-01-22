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

#include "ft_io.h"

#include "wrap.h"

#define WRITE_SIZE_MAX 1048576

t_err	ft_io_write(
	int fd,
	const void *buf,
	size_t len
)
{
	size_t		remain;
	size_t		to_write;
	ssize_t		wrote;
	const char	*str;

	str = (const char *)buf;
	remain = len;
	while (remain)
	{
		to_write = remain;
		if (to_write > WRITE_SIZE_MAX)
			to_write = WRITE_SIZE_MAX;
		wrote = wrap_write(fd, str, to_write);
		if (wrote < 0)
			return (true);
		remain -= (size_t)wrote;
		str = str + wrote;
	}
	return (false);
}
