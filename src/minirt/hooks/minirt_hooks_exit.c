/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_hooks_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 22:46:43 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2023/01/07 16:12:06 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_hooks.h"

#include <stdlib.h>

#include "ft_exit.h"

int	minirt_hooks_exit(int unused, t_minirt *param)
{
	(void)unused;
	(void)param;
	ft_exit(EXIT_SUCCESS);
	return (0);
}
