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

t_err	ft_io_le_write_u32(int fd, uint32_t u32)
{
	const uint32_t		test = 42;
	const char *const	result = (const char *)&u32;

	if (*((char *)&test))
		return (ft_io_write(fd, result, 4));
	return (
		false
		|| ft_io_write(fd, &result[3], 1)
		|| ft_io_write(fd, &result[2], 1)
		|| ft_io_write(fd, &result[1], 1)
		|| ft_io_write(fd, &result[0], 1)
	);
}
