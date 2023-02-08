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

t_f	t_f_exp(t_f f)
{
	return (expl(f));
}

#elif PRECISION == 1

t_f	t_f_exp(t_f f)
{
	return (exp(f));
}

#elif PRECISION == 2

t_f	t_f_exp(t_f f)
{
	return (expf(f));
}

#elif PRECISION == 3

t_f	t_f_exp(t_f f)
{
	return ((t_f)expf((float)f));
}

#endif
