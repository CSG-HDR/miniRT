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

#include <stddef.h>

#include "t_map_polynomial_plane.h"

size_t	t_map_polynomial_plane_validate_coefficient_size(const char *str)
{
	size_t	result;

	result = 0;
	while (0 <= str[result] && str[result] <= '9')
		result++;
	if (str[result] == '.')
	{
		result++;
		while ('0' <= str[result] && str[result] <= '9')
			result++;
	}
	return (result);
}
