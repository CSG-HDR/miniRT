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

void	t_ray_nearest_quartic_c112(
	t_ray_nearest_quartic_vars v,
	t_map_quartic q,
	t_ray_nearest_quartic_equation *mut_result
)
{
	const t_f	c = q.c121;

	mut_result->e += c * v.p * v.q * v.r * v.r;
	mut_result->d += 2 * c * v.p * v.q * v.r * v.w;
	mut_result->c += c * v.p * v.q * v.w * v.w;
	mut_result->d += c * v.p * v.r * v.r * v.v;
	mut_result->c += 2 * c * v.p * v.r * v.v * v.w;
	mut_result->b += c * v.p * v.v * v.w * v.w;
	mut_result->d += c * v.q * v.r * v.r * v.u;
	mut_result->c += 2 * c * v.q * v.r * v.u * v.w;
	mut_result->b += c * v.q * v.u * v.w * v.w;
	mut_result->c += c * v.r * v.r * v.u * v.v;
	mut_result->b += 2 * c * v.r * v.u * v.v * v.w;
	mut_result->a += c * v.u * v.v * v.w * v.w;
}
