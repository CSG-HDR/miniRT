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

#define READ_SIZE_MAX 1048576

t_err	ft_io_read(int fd, void *buf, size_t len)
{
	size_t	remain;
	size_t	to_read;
	ssize_t	read;
	char	*str;

	str = (char *)buf;
	remain = len;
	while (remain)
	{
		to_read = remain;
		if (to_read > READ_SIZE_MAX)
			to_read = READ_SIZE_MAX;
		read = wrap_read(fd, str, to_read);
		if (read <= 0)
			return (true);
		remain -= (size_t)read;
		str = str + read;
	}
	return (false);
}
