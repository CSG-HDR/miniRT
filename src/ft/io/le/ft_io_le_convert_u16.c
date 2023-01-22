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

uint16_t	ft_io_le_convert_u16(uint16_t u16)
{
	const uint16_t		test = 42;
	const char *const	source = (const char *)&u16;
	uint16_t			result;
	char *const			dest = (char *)&result;

	if (*((char *)&test))
		return (u16);
	dest[0] = source[1];
	dest[1] = source[0];
	return (result);
}
