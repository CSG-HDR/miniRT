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

#define W 1920
#define H 1080
#define TITLE "CSG+HDR minirt!"

void	minirt_init(t_minirt *minirt, int argc, char **argv)
{
	(void)argv;
	if (argc < 2)
	{
		ft_write(STDOUT_FILENO, "Error: no input file\n", 21);
		ft_exit(1);
	}
	minirt->mlx_context = mlx_init();
	if (!minirt->mlx_context)
	{
		ft_write(STDOUT_FILENO, "Error: no input file\n", 21);
		ft_exit(1);
	}
	minirt->mlx_window = mlx_new_window(minirt->mlx_context, W, H, TITLE);
	minirt->pre_image = mlx_new_image(minirt->mlx_context, W, H);
	minirt->final_image = mlx_new_image(minirt->mlx_context, W, H);
	mlx_expose_hook(minirt->mlx_window, &minirt_hooks_init, minirt);
	mlx_hook(minirt->mlx_window, MLX_EVENT_ON_DESTROY,
		0, &minirt_hooks_exit, minirt);
	mlx_hook(minirt->mlx_window, MLX_EVENT_ON_KEYDOWN,
		0, &minirt_hooks_key, minirt);
}
