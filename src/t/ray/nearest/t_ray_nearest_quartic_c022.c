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

void	t_ray_nearest_quartic_c022(
	t_ray_nearest_quartic_vars v,
	t_map_quartic q,
	t_ray_nearest_quartic_equation *mut_result
)
{
	const t_f	c = q.c022;

	mut_result->e += c * v.q * v.q * v.r * v.r;
	mut_result->d += 2 * c * v.q * v.q * v.r * v.w;
	mut_result->c += c * v.q * v.q * v.w * v.w;
	mut_result->d += 2 * c * v.q * v.r * v.r * v.v;
	mut_result->c += 4 * c * v.q * v.r * v.v * v.w;
	mut_result->b += 2 * c * v.q * v.v * v.w * v.w;
	mut_result->c += c * v.r * v.r * v.v * v.v;
	mut_result->b += 2 * c * v.r * v.v * v.v * v.w;
	mut_result->a += c * v.v * v.v * v.w * v.w;
}
