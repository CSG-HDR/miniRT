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

#ifndef T_IMAGE_H
# define T_IMAGE_H

# include <stddef.h>

# include "ft_types.h"
# include "t_f3.h"

typedef struct s_image
{
	size_t	width;
	size_t	height;
	t_f3	extra[];
}	t_image;

t_err	t_image_print_as_bmp(t_image *self);

#endif
