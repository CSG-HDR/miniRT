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

t_err	ft_io_be_write_u64(int fd, uint64_t u64)
{
	const uint64_t		test = 42;
	const char *const	result = (const char *)&u64;

	if (!*((char *)&test))
		return (ft_io_write(fd, result, 8));
	return (
		false
		|| ft_io_write(fd, &result[7], 1)
		|| ft_io_write(fd, &result[6], 1)
		|| ft_io_write(fd, &result[5], 1)
		|| ft_io_write(fd, &result[4], 1)
		|| ft_io_write(fd, &result[3], 1)
		|| ft_io_write(fd, &result[2], 1)
		|| ft_io_write(fd, &result[1], 1)
		|| ft_io_write(fd, &result[0], 1)
	);
}
