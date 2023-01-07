/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_hooks_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 23:52:02 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2023/01/07 16:11:44 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_hooks.h"

int	minirt_hooks_init(t_minirt *param)
{
	minirt_render(param);
	return (0);
}
