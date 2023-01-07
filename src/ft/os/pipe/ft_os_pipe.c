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

#include "ft_os_pipe.h"

#include "wrap.h"

t_err	ft_os_pipe(int *in_to_write, int *out_to_read)
{
	int	fds[2];

	if (wrap_pipe(fds) < 0)
		return (true);
	*in_to_write = fds[1];
	*out_to_read = fds[0];
	return (false);
}
