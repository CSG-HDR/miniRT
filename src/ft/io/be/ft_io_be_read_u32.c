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

t_err	ft_io_be_read_u32(int fd, uint32_t *out_u32)
{
	const uint32_t	test = 42;
	char *const		buffer = (char *)out_u32;

	if (!*((char *)&test))
		return (ft_io_read(fd, buffer, 4));
	return (
		false
		|| ft_io_read(fd, &buffer[3], 1)
		|| ft_io_read(fd, &buffer[2], 1)
		|| ft_io_read(fd, &buffer[1], 1)
		|| ft_io_read(fd, &buffer[0], 1)
	);
}
