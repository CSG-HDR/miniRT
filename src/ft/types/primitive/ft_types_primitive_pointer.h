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

#ifndef FT_TYPES_PRIMITIVE_POINTER_H
# define FT_TYPES_PRIMITIVE_POINTER_H

# include <stdbool.h>

void	ft_types_primitive_pointer_swap(void **a, void **b);
void	*ft_types_primitive_pointer_if(
			bool condition,
			void *value_if_true,
			void *value_if_false);

#endif
