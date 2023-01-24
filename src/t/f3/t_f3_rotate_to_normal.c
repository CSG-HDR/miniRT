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

#include "t_f3.h"

t_f3	t_f3_rotate_to_normal(t_f3 rotate)
{
	// rotate (1, 0, 0) by axis for each theta.
	const t_f	theta_x = 2 * M_PI * rotate.x;
	const t_f	theta_y = 2 * M_PI * rotate.y;
	const t_f	theta_z = 2 * M_PI * rotate.z;

	// TODO: rotated noraml using quaternion
	t_f3 normal;
	normal.x = theta_x;
	normal.y = theta_y;
	normal.z = theta_z;
	return (normal);
}