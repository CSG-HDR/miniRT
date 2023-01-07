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

#include "ft_malloc.h"

#include "wrap.h"
#include "ft_exit.h"

void	*ft_nonnull(void *p)
{
	if (!p)
		ft_exit(EXIT_FAILURE);
	return (p);
}

void	*ft_malloc(size_t size)
{
	return (ft_nonnull(wrap_malloc(size)));
}
