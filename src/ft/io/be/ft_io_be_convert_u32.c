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

uint32_t	ft_io_be_convert_u32(uint32_t u32)
{
	const uint32_t		test = 42;
	const char *const	source = (const char *)&u32;
	uint32_t			result;
	char *const			dest = (char *)&result;

	if (!*((char *)&test))
		return (u32);
	dest[0] = source[3];
	dest[1] = source[2];
	dest[2] = source[1];
	dest[3] = source[0];
	return (result);
}
