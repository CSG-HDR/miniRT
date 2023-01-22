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

t_err	ft_io_le_read_u16(int fd, uint16_t *out_u16)
{
	const uint16_t	test = 42;
	char *const		buffer = (char *)out_u16;

	if (*((char *)&test))
		return (ft_io_read(fd, buffer, 2));
	return (
		false
		|| ft_io_read(fd, &buffer[1], 1)
		|| ft_io_read(fd, &buffer[0], 1)
	);
}
