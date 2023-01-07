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

#include "ft_memory.h"

#include "wrap.h"

void	*ft_memory_allocate(size_t count, size_t size)
{
	const size_t	total_size = count * size;
	void *const		result = wrap_malloc(total_size);

	if (!result)
		return (NULL);
	ft_memory_zero(result, total_size);
	return (result);
}
