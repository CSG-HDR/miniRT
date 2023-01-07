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

t_err	ft_to_lines_feed(
	t_ft_to_lines *context,
	const void *append,
	size_t append_length
)
{
	if (context->pending)
		return (true);
	context->pending = (const char *)append;
	context->pending_offset = 0;
	context->pending_length = append_length;
	return (false);
}
