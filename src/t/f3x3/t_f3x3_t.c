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

t_f3x3	t_f3x3_t(t_f3x3 mat)
{
	return ((t_f3x3){
		t_f3x3_col_x(mat),
		t_f3x3_col_y(mat),
		t_f3x3_col_z(mat),
	});
}
