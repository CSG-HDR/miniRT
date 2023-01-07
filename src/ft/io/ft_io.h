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

#ifndef FT_IO_H
# define FT_IO_H

# include <stddef.h>

# include "ft_types.h"

t_err	ft_write(
			int fd,
			const void *buf,
			size_t len);

t_err	ft_puts(int fd, const char *str);
t_err	ft_putn(int fd, int n);
t_err	ft_puts_prefix(
			int fd,
			const char *str,
			const char *prefix);

#endif
