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

#include "ft_os_fork.h"

t_err	ft_os_fork_multiple(
	size_t count,
	pid_t *out,
	size_t *out_index,
	size_t *out_count
)
{
	size_t	i;

	i = -1;
	while (++i < count)
	{
		if (ft_os_fork(&out[i]))
		{
			*out_count = i;
			return (true);
		}
		if (out[i] == 0)
		{
			*out_index = i;
			return (false);
		}
	}
	*out_index = -1;
	return (false);
}
