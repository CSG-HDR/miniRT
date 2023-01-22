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

#include "ft_byte_map.h"

#include <stddef.h>
#include <limits.h>
#include <stdarg.h>

#include "ft_types.h"

#ifdef DEVELOPMENT

# include "ft_debug.h"

void	ft_byte_map(t_byte *out, bool include_null, const t_byte *set)
{
	size_t			i;
	const t_byte	*tmp;

	if (!out || !set)
		ft_debug_die("ft_byte_map(): wrong parameter given\n");
	i = 0;
	while (i < 1 << CHAR_BIT)
		out[i++] = 0;
	if (include_null)
		out[0] = 1;
	if (!set)
		return ;
	tmp = (const unsigned char *) set;
	while (*tmp)
		out[*tmp++] = 1;
}

void	ft_byte_map_v(t_byte *out, bool include_null, va_list arguments)
{
	size_t			i;
	const t_byte	*tmp;

	if (!out)
		ft_debug_die("ft_byte_map_v(): wrong parameter given\n");
	i = 0;
	while (i < 1 << CHAR_BIT)
		out[i++] = 0;
	if (include_null)
		out[0] = 1;
	tmp = va_arg(arguments, const t_byte *);
	while (tmp)
	{
		while (*tmp)
			out[*tmp++] = 1;
		tmp = va_arg(arguments, const t_byte *);
	}
}

#else

void	ft_byte_map(t_byte *out, bool include_null, const t_byte *set)
{
	size_t			i;
	const t_byte	*tmp;

	i = 0;
	while (i < 1 << CHAR_BIT)
		out[i++] = 0;
	if (include_null)
		out[0] = 1;
	if (!set)
		return ;
	tmp = (const unsigned char *) set;
	while (*tmp)
		out[*tmp++] = 1;
}

void	ft_byte_map_v(t_byte *out, bool include_null, va_list arguments)
{
	size_t			i;
	const t_byte	*tmp;

	i = 0;
	while (i < 1 << CHAR_BIT)
		out[i++] = 0;
	if (include_null)
		out[0] = 1;
	tmp = va_arg(arguments, const t_byte *);
	while (tmp)
	{
		while (*tmp)
			out[*tmp++] = 1;
		tmp = va_arg(arguments, const t_byte *);
	}
}

#endif

void	ft_byte_map_va(t_byte *out, int include_null, ...)
{
	va_list			arguments;

	va_start(arguments, include_null);
	ft_byte_map_v(out, include_null, arguments);
	va_end(arguments);
}
