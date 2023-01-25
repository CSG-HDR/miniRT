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

#ifndef MINIRT_H
# define MINIRT_H

# include "ft_types.h"
# include "t_image.h"
# include "t_map.h"

typedef struct s_minirt_mlx_image
{
	int				bits_per_pixel;
	int				size_of_line;
	int				endian;
	unsigned char	*data;
}	t_minirt_mlx_image;

typedef struct s_minirt
{
	void				*mlx_context;
	void				*mlx_window;
	void				*mlx_image;
	t_minirt_mlx_image	image;
	t_map				*map;
}	t_minirt;

typedef enum e_minirt_load_map_error
{
	MINIRT_LOAD_MAP_ERROR_SUCCESS = 0,
	MINIRT_LOAD_MAP_ERROR_READ_FILE,
	MINIRT_LOAD_MAP_ERROR_INVALID_JSON_FORMAT,
	MINIRT_LOAD_MAP_ERROR_INVALID_RT_SCHEMA,
	MINIRT_LOAD_MAP_ERROR_MALLOC,
}	t_minirt_load_map_error;

void					minirt_die(const char *message);
void					minirt_assert(
							void **dest, void *value, const char *message);
void					minirt_init(t_minirt *minirt, int argc, char **argv);
t_minirt_load_map_error	minirt_load_map(const char *path, t_map **out);
void					minirt_load_map_die(t_minirt_load_map_error error);
void					minirt_render(t_minirt *param);
t_err					minirt_image_to_mlx_image_pixel(
							t_image *param,
							t_minirt_mlx_image *image,
							size_t x,
							size_t y);
t_err					minirt_image_to_mlx_image(
							t_image *param,
							t_minirt_mlx_image *image);

#endif
