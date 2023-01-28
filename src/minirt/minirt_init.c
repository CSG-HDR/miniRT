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

#include "minirt.h"

#include <unistd.h>

#include "mlx.h"

#include "ft_exit.h"
#include "ft_io.h"
#include "t_image.h"
#include "t_texture_manager.h"
#include "minirt_hooks.h"

#define TITLE "CSG+HDR minirt!"

static void	init_mlx(t_minirt *m)
{
	minirt_assert(&m->mlx_context, mlx_init(), "Error: on init mlx\n");
	minirt_assert(
		&m->mlx_window, mlx_new_window(
			m->mlx_context,
			m->map->viewport.actual_width,
			m->map->viewport.actual_height,
			TITLE),
		"Error: on init mlx window\n");
	minirt_assert(
		&m->mlx_image,
		mlx_new_image(
			m->mlx_context,
			m->map->viewport.actual_width,
			m->map->viewport.actual_height),
		"Error: on init mlx image\n");
	m->image.data
		= (unsigned char *)mlx_get_data_addr(
			m->mlx_image,
			&m->image.bits_per_pixel,
			&m->image.size_of_line,
			&m->image.endian);
	mlx_expose_hook(m->mlx_window, &minirt_hooks_init, m);
	mlx_hook(m->mlx_window, MLX_EVENT_ON_DESTROY, 0, &minirt_hooks_exit, m);
	mlx_hook(m->mlx_window, MLX_EVENT_ON_KEYDOWN, 0, &minirt_hooks_key, m);
}

void	minirt_init(t_minirt *m, int argc, char **argv)
{
	t_minirt_load_map_error	error;

	if (argc < 2)
		minirt_die("Error: no input file\n");
	error = minirt_load_map(argv[1], &m->map);
	if (error)
		minirt_load_map_die(error);
	m->texture_manager = t_texture_manager_new();
	if (!m->texture_manager
		|| t_texture_manager_preload_models(
			m->texture_manager,
			m->map->models,
			m->map->model_count))
		minirt_die("Error: on load textures\n");
	init_mlx(m);
	minirt_assert(
		(void **)&m->tmp,
		t_image_new(
			m->map->viewport.actual_width,
			m->map->viewport.actual_height,
			NULL,
			NULL),
		"Error: on init image\n");
}
