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

#include "ft_to_lines.h"

static bool	ft_memory_find(
	const void *mem,
	size_t size,
	char to_find,
	size_t *out
)
{
	const char *const	mem_c = (char *)mem;
	size_t				i;

	i = 0;
	while (i < size)
	{
		if (mem_c[i] == to_find)
		{
			if (out)
				*out = i;
			return (true);
		}
		i++;
	}
	return (false);
}

static t_err	ft_to_lines_internal_append(
	t_ft_to_lines *context,
	char **out_line
)
{
	if (!context->current)
		context->current = new_stringbuilder(context->buffer_size);
	if (!context->current)
		return (true);
	if (stringbuilder_append(
			context->current,
			context->pending_length - context->pending_offset,
			&context->pending[context->pending_offset]))
		return (true);
	context->pending = NULL;
	*out_line = NULL;
	return (false);
}

static t_err	ft_to_lines_internal_final(
	t_ft_to_lines *context,
	char **out_line,
	size_t *out_line_length,
	size_t length
)
{
	if (!context->current)
		context->current = new_stringbuilder(context->buffer_size);
	if (!context->current)
		return (true);
	if (stringbuilder_append(
			context->current,
			length,
			&context->pending[context->pending_offset]))
		return (true);
	context->pending_offset += length;
	if (context->pending_offset == context->pending_length)
		context->pending = NULL;
	if (ft_to_lines_get_current_line(context, out_line, out_line_length))
		return (true);
	stringbuilder_free(context->current);
	context->current = NULL;
	return (false);
}

t_err	ft_to_lines_drain(
	t_ft_to_lines *context,
	char **out_line,
	size_t *out_line_length
)
{
	size_t	position;

	if (!context->pending)
	{
		*out_line = NULL;
		return (false);
	}
	if (ft_memory_find(
			&context->pending[context->pending_offset],
			context->pending_length - context->pending_offset,
			'\n',
			&position))
		return (ft_to_lines_internal_final(
				context,
				out_line,
				out_line_length,
				position + 1));
	return (ft_to_lines_internal_append(context, out_line));
}
