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

#include "wrap.h"

#include <stdarg.h>
#include <fcntl.h>

#ifdef O_TMPFILE

static const int	g_flags = O_CREAT | O_TMPFILE;

#else

static const int	g_flags = O_CREAT;

#endif

int	wrap_open(const char *path, int flags, ...)
{
	va_list	ap;
	int		additional_flags;

	if (flags & g_flags)
	{
		va_start(ap, flags);
		additional_flags = va_arg(ap, int);
		va_end(ap);
		return (open(path, flags, additional_flags));
	}
	return (open(path, flags));
}
