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

t_err	ft_to_lines_get_current_line(
	t_ft_to_lines *context,
	char **out_line,
	size_t *out_line_length
)
{
	if (!context->current)
	{
		*out_line = NULL;
		return (false);
	}
	*out_line = stringbuilder_to_string(context->current, 0);
	if (!*out_line)
		return (true);
	*out_line_length = context->current->length;
	return (false);
}
