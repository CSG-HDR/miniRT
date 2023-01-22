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

t_err	ft_io_le_write_u16(int fd, uint16_t u16)
{
	const uint16_t		test = 42;
	const char *const	result = (const char *)&u16;

	if (*((char *)&test))
		return (ft_io_write(fd, result, 2));
	return (
		false
		|| ft_io_write(fd, &result[1], 1)
		|| ft_io_write(fd, &result[0], 1)
	);
}
