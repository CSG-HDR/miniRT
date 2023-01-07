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

#include "ft_os_file.h"

#include "wrap.h"

#include "ft_cstring.h"
#include "ft_memory.h"

t_ft_os_file	*ft_os_file_open2(const char *path, int mode, int permission)
{
	const int			fd = wrap_open(path, mode, permission);
	const size_t		path_length = ft_cstring_length(path);
	t_ft_os_file *const	result
		= wrap_malloc(sizeof(t_ft_os_file) + path_length + 1);

	if (fd < 0 || !result)
	{
		if (fd < 0)
			wrap_close(fd);
		wrap_free(result);
		return (NULL);
	}
	result->fd = fd;
	result->mode = mode;
	ft_memory_copy(result->path, path, path_length + 1);
	return (result);
}
