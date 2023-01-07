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

#ifndef FT_OS_FORK_H
# define FT_OS_FORK_H

# include <unistd.h>

# include "ft_types.h"

t_err	ft_os_fork(
			pid_t *out_pid);
t_err	ft_os_fork_multiple(
			size_t count,
			pid_t *out,
			size_t *out_index,
			size_t *out_count);

#endif
