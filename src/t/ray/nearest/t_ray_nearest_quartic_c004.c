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

#include "t_ray.h"

void	t_ray_nearest_quartic_c004(
	t_ray_nearest_quartic_vars v,
	t_map_quartic q,
	t_ray_nearest_quartic_equation *mut_result
)
{
	const t_f	c = q.c004;

	mut_result->e += c * v.r * v.r * v.r * v.r;
	mut_result->d += 4 * c * v.r * v.r * v.r * v.w;
	mut_result->c += 6 * c * v.r * v.r * v.w * v.w;
	mut_result->b += 4 * c * v.r * v.w * v.w * v.w;
	mut_result->a += c * v.w * v.w * v.w * v.w;
}
