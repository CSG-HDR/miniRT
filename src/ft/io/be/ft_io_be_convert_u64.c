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

uint64_t	ft_io_be_convert_u64(uint64_t u64)
{
	const uint64_t		test = 42;
	const char *const	source = (const char *)&u64;
	uint64_t			result;
	char *const			dest = (char *)&result;

	if (!*((char *)&test))
		return (u64);
	dest[0] = source[7];
	dest[1] = source[6];
	dest[2] = source[5];
	dest[3] = source[4];
	dest[4] = source[3];
	dest[5] = source[2];
	dest[6] = source[1];
	dest[7] = source[0];
	return (result);
}
