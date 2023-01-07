/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_hooks_key.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 22:47:32 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2023/01/07 16:11:22 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_hooks.h"

#include <stdlib.h>

#include "ft_exit.h"

int	minirt_hooks_key(int keycode, t_minirt *param)
{
	(void)param;
	if (keycode == MLX_KEY_ESC)
		ft_exit(EXIT_SUCCESS);
	return (0);
}
