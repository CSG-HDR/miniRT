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

#include "minirt_hooks.h"

#define TITLE "CSG+HDR minirt!"

void	minirt_init(t_minirt *minirt, int argc, char **argv)
{
	t_minirt_load_map_error	error;

	(void)argv;
	if (argc < 2)
		minirt_die("Error: no input file\n");
	minirt_assert(&minirt->mlx_context, mlx_init(), "Error: on init mlx");
	error = minirt_load_map(argv[1], &minirt->map);
	if (error)
		minirt_load_map_die(error);
	minirt_assert(&minirt->mlx_window, mlx_new_window(minirt->mlx_context,
			minirt->map->viewport.actual_width, minirt->map->viewport
			.actual_height, TITLE), "Error: on init mlx window");
	minirt_assert(&minirt->pre_image, mlx_new_image(minirt->mlx_context,
			minirt->map->viewport.actual_width, minirt->map->viewport
			.actual_height), "Error: on init mlx image (1/2)");
	minirt_assert(&minirt->final_image, mlx_new_image(minirt->mlx_context,
			minirt->map->viewport.actual_width, minirt->map->viewport
			.actual_height), "Error: on init mlx image (2/2)");
	mlx_expose_hook(minirt->mlx_window, &minirt_hooks_init, minirt);
	mlx_hook(minirt->mlx_window, MLX_EVENT_ON_DESTROY,
		0, &minirt_hooks_exit, minirt);
	mlx_hook(minirt->mlx_window, MLX_EVENT_ON_KEYDOWN,
		0, &minirt_hooks_key, minirt);
}
