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

char	*ft_to_lines_end(t_ft_to_lines *context)
{
	char	*result;

	result = NULL;
	if (context->current)
	{
		result = stringbuilder_to_string(context->current, 0);
		stringbuilder_free(context->current);
	}
	return (result);
}
