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

void	t_ray_nearest_quartic_c220(
	t_ray_nearest_quartic_vars v,
	t_map_quartic q,
	t_ray_nearest_quartic_equation *mut_result
)
{
	const t_f	c = q.c220;

	mut_result->e += c * v.p * v.p * v.q * v.q;
	mut_result->d += 2 * c * v.p * v.p * v.q * v.v;
	mut_result->c += c * v.p * v.p * v.v * v.v;
	mut_result->d += 2 * c * v.p * v.q * v.q * v.u;
	mut_result->c += 4 * c * v.p * v.q * v.u * v.v;
	mut_result->b += 2 * c * v.p * v.u * v.v * v.v;
	mut_result->c += c * v.q * v.q * v.u * v.u;
	mut_result->b += 2 * c * v.q * v.u * v.u * v.v;
	mut_result->a += c * v.u * v.u * v.v * v.v;
}
