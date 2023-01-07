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

#include "ft_types_primitive_size_t.h"

void	ft_types_primitive_size_t_swap(size_t *a, size_t *b)
{
	size_t	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

size_t	ft_types_primitive_size_t_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

size_t	ft_types_primitive_size_t_max(size_t a, size_t b)
{
	if (a > b)
		return (a);
	return (b);
}

size_t	ft_types_primitive_size_t_if(
	bool condition,
	size_t value_if_true,
	size_t value_if_false
)
{
	if (condition)
		return (value_if_true);
	else
		return (value_if_false);
}
