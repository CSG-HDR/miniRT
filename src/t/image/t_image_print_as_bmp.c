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

#include "t_image.h"

#include <stdio.h>
#include <stddef.h>
#include <unistd.h>

#include "ft_io.h"
#include "wrap.h"

t_err	t_image_print_as_bmp(t_image *self)
{
	char	*str;
	size_t	length;

	if (t_image_serialize(self, &str, &length))
		return (true);
	if (ft_io_write(STDOUT_FILENO, str, length))
	{
		wrap_free(str);
		return (true);
	}
	wrap_free(str);
	return (false);
}
