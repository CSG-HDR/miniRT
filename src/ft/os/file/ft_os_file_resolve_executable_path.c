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

#include "ft_cstring.h"

#include "wrap.h"
#include "ft_os_file.h"

static t_err	to_full_path(const char *path, const char *name, char **out)
{
	char	*tmp;
	char	*temp;

	if (ft_cstring_ends_with_char(path, '/'))
	{
		if (ft_cstring_concat(path, name, &tmp))
			return (true);
		*out = tmp;
		return (false);
	}
	if (ft_cstring_concat(path, "/", &temp))
		return (NULL);
	if (ft_cstring_concat(temp, name, &tmp))
	{
		wrap_free(temp);
		return (true);
	}
	wrap_free(temp);
	*out = tmp;
	return (false);
}

t_err	ft_os_file_resolve_executable_path(
	const char *name,
	const char *const *path,
	char **out
)
{
	const char *const	*tmp;
	char				*full_path;

	*out = NULL;
	if (ft_cstring_contains_char(name, '/'))
		return (ft_cstring_duplicate(name, out));
	if (!path)
		return (false);
	tmp = path - 1;
	while (*++tmp)
	{
		if (to_full_path(*tmp, name, &full_path))
			return (true);
		if (ft_os_file_is_executable(full_path))
		{
			*out = full_path;
			return (false);
		}
		wrap_free(full_path);
	}
	return (false);
}
