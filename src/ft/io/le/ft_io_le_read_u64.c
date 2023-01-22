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

#include <stdint.h>

#include "ft_types.h"

t_err	ft_io_le_read_u64(int fd, uint64_t *out_u64)
{
	const uint64_t	test = 42;
	char *const		buffer = (char *)out_u64;

	if (*((char *)&test))
		return (ft_io_read(fd, buffer, 8));
	return (
		false
		|| ft_io_read(fd, &buffer[7], 1)
		|| ft_io_read(fd, &buffer[6], 1)
		|| ft_io_read(fd, &buffer[5], 1)
		|| ft_io_read(fd, &buffer[4], 1)
		|| ft_io_read(fd, &buffer[3], 1)
		|| ft_io_read(fd, &buffer[2], 1)
		|| ft_io_read(fd, &buffer[1], 1)
		|| ft_io_read(fd, &buffer[0], 1)
	);
}
