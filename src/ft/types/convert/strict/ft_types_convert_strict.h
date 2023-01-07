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

#ifndef FT_TYPES_CONVERT_STRICT_H
# define FT_TYPES_CONVERT_STRICT_H

# include "ft_types.h"

t_err	ft_types_convert_strict_string_to_int(
			const char *str,
			int *out);
t_err	ft_types_convert_strict_string_to_long_double(
			const char *str,
			long double *out);

#endif
