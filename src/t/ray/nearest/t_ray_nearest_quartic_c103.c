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

void	t_ray_nearest_quartic_c103(
	t_ray_nearest_quartic_vars v,
	t_map_quartic q,
	t_ray_nearest_quartic_equation *mut_result
)
{
	const t_f	c = q.c103;

	mut_result->e += c * v.p * v.r * v.r * v.r;
	mut_result->d += 3 * c * v.p * v.r * v.r * v.w;
	mut_result->c += 3 * c * v.p * v.r * v.w * v.w;
	mut_result->b += c * v.p * v.w * v.w * v.w;
	mut_result->d += c * v.r * v.r * v.r * v.u;
	mut_result->c += 3 * c * v.r * v.r * v.u * v.w;
	mut_result->b += 3 * c * v.r * v.u * v.w * v.w;
	mut_result->a += c * v.u * v.w * v.w * v.w;
}
