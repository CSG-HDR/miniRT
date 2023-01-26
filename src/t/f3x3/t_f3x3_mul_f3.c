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

#include "t_f3x3.h"

#include "t_f3.h"

t_f3	t_f3x3_mul_f3(t_f3x3 mat, t_f3 vec)
{
	return ((t_f3){
		t_f3_dot(mat.x, vec),
		t_f3_dot(mat.y, vec),
		t_f3_dot(mat.z, vec),
	});
}
