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

void	t_ray_nearest_quartic_c400(
	t_ray_nearest_quartic_vars v,
	t_map_quartic q,
	t_ray_nearest_quartic_equation *mut_result
)
{
	const t_f	c = q.c400;

	mut_result->e += c * v.p * v.p * v.p * v.p;
	mut_result->d += 4 * c * v.p * v.p * v.p * v.u;
	mut_result->c += 6 * c * v.p * v.p * v.u * v.u;
	mut_result->b += 4 * c * v.p * v.u * v.u * v.u;
	mut_result->a += c * v.u * v.u * v.u * v.u;
}
