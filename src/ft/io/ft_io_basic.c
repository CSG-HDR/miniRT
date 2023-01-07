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
#include "ft_cstring.h"

#define WRITE_SIZE_MAX 1048576

t_err	ft_write(
	int fd,
	const void *buf,
	size_t len
)
{
	size_t		remain;
	size_t		to_write;
	ssize_t		wrote;
	const char	*str;

	str = (const char *) buf;
	remain = len;
	while (remain)
	{
		to_write = remain;
		if (to_write > WRITE_SIZE_MAX)
			to_write = WRITE_SIZE_MAX;
		wrote = wrap_write(fd, str, to_write);
		if (wrote < 0)
			return (1);
		remain -= (size_t) wrote;
		str = str + wrote;
	}
	return (0);
}

t_err	ft_puts(int fd, const char *str)
{
	return (ft_write(fd, str, ft_cstring_length(str)));
}

static t_err	ft_putn_internal(int fd, int i)
{
	int	sgn;

	sgn = 1;
	if (i < 0)
		sgn = -1;
	if (!i)
		return (0);
	return (ft_putn_internal(fd, i / 10)
		|| ft_write(fd, &"0123456789"[(i % 10) * sgn], 1));
}

t_err	ft_putn(int fd, int i)
{
	if (!i)
		return (ft_puts(fd, "0"));
	return (ft_putn_internal(fd, i));
}

t_err	ft_puts_prefix(
	int fd,
	const char *str,
	const char *prefix
)
{
	const size_t	prefix_length = ft_cstring_length(prefix);
	size_t			length;

	while (true)
	{
		length = ft_strlen_until_set(str, "\n", true);
		if (ft_write(fd, str, length))
			return (true);
		str += length;
		if (!*str)
			return (false);
		str++;
		if (ft_write(fd, "\n", 1)
			|| ft_write(fd, prefix, prefix_length))
			return (true);
	}
}
