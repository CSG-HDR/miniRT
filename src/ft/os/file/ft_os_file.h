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

#ifndef FT_OS_FILE_H
# define FT_OS_FILE_H

# include <stddef.h>

# include "ft_types.h"

typedef struct s_ft_os_file
{
	int		fd;
	int		mode;
	char	path[];
}	t_ft_os_file;

t_ft_os_file	*ft_os_file_open(const char *path, int mode);
t_ft_os_file	*ft_os_file_open2(const char *path, int mode, int permission);
void			ft_os_file_close(t_ft_os_file *file);

char			*ft_os_file_read(const char *filename);

#endif
