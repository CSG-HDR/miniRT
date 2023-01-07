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

#include "ft_types_convert_strict.h"

#include <stdbool.h>

typedef struct s_ft_types_convert_strict_string_to_long_double_internal_stack
{
	int			sgn;
	long double	result;
	bool		decimal;
	long double	radix;
}	t_ft_types_convert_strict_string_to_long_double_internal_stack;

static t_err	process_char(
	t_ft_types_convert_strict_string_to_long_double_internal_stack *s,
	char c
)
{
	if (c == '.')
	{
		if (!s->decimal)
			return (true);
		s->radix = 1.0L;
		s->decimal = false;
		return (false);
	}
	if (c < '0' || c > '9')
	{
		return (true);
	}
	if (s->decimal)
	{
		s->result = s->result * 10 + (c - '0') * s->sgn;
	}
	else
	{
		s->radix /= 10;
		s->result += s->radix * (c - '0');
	}
	return (false);
}

t_err	ft_types_convert_strict_string_to_long_double(
	const char *str,
	long double *out
)
{
	t_ft_types_convert_strict_string_to_long_double_internal_stack	s;

	if (!str[0]
		|| (str[0] == '.')
		|| (str[0] == '-' && str[1] == '.')
		|| (str[0] == '-' && !str[1])
		|| (str[0] == '-' && str[1] == '0' && str[2] != '.')
		|| (str[0] == '0' && str[1] && str[1] != '.'))
		return (true);
	s.result = 0.0L;
	s.sgn = 1;
	if (*str == '-' && *str++)
		s.sgn = -1;
	s.decimal = true;
	while (*str)
		if (process_char(&s, *str++))
			return (true);
	if (!s.decimal && s.radix == 1.0L)
		return (true);
	*out = s.result * s.sgn;
	return (false);
}
