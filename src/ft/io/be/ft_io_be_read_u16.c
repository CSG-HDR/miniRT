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

t_err	ft_io_be_read_u16(int fd, uint16_t *out_u16)
{
	uint16_t	buffer;

	if (ft_io_read(fd, &buffer, 2))
		return (true);
	*out_u16 = ft_io_be_convert_u16(buffer);
	return (false);
}
