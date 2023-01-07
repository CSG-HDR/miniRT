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

#include "ft_os_process.h"

#include <sys/wait.h>

#include "wrap.h"

int	ft_os_process_wait_pids(pid_t *pids, size_t count)
{
	size_t	i;
	int		last_stat_loc;

	i = -1;
	while (++i < count)
		wrap_waitpid(pids[i], &last_stat_loc, 0);
	return (WEXITSTATUS(last_stat_loc));
}
