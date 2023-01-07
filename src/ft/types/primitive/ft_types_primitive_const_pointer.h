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

#ifndef FT_TYPES_PRIMITIVE_CONST_POINTER_H
# define FT_TYPES_PRIMITIVE_CONST_POINTER_H

# include <stdbool.h>

void		ft_types_primitive_const_pointer_swap(
				const void **a,
				const void **b);
const void	*ft_types_primitive_const_pointer_if(
				bool condition,
				const void *value_if_true,
				const void *value_if_false);

#endif
