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

#include "t_f.h"

#include <math.h>

#if PRECISION == 0

t_f	t_f_cos(t_f f)
{
	return (cosl(f));
}

#elif PRECISION == 1

t_f	t_f_cos(t_f f)
{
	return (cos(f));
}

#elif PRECISION == 2

t_f	t_f_cos(t_f f)
{
	return (cosf(f));
}

#elif PRECISION == 3

t_f	t_f_cos(t_f f)
{
	return ((t_f)cosf((float)f));
}

#endif
