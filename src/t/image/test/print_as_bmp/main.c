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
#include "t_f.h"
#include "t_f3.h"
#include "t_image.h"

#define WIDTH 1920
#define HEIGHT 1080

static t_err	fill_image(void *context, size_t x, size_t y, t_f3 *out)
{
	const t_f	x_ratio = x / (WIDTH - 1);
	const t_f	y_ratio = y / (HEIGHT - 1);

	(void)context;
	*out = (t_f3){x_ratio, y_ratio, 1};
	return (false);
}

int	main(void)
{
	t_image *const	image = t_image_new(WIDTH, HEIGHT, fill_image, NULL);

	if (!image)
		return (EXIT_FAILURE);
	t_image_print_as_bmp(image);
	wrap_free(image);
}
