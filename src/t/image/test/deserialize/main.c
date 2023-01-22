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

#include <stdlib.h>

#include "wrap.h"
#include "ft_types.h"
#include "ft_os_file.h"
#include "t_image.h"

int	main(void)
{
	size_t		length;
	t_image		*image;
	char *const	str = ft_os_file_read("result.bmp", &length);

	if (!str || t_image_deserialize(str, length, &image))
	{
		wrap_free(str);
		return (EXIT_FAILURE);
	}
	t_image_print_as_bmp(image);
	wrap_free(image);
	wrap_free(str);
}
