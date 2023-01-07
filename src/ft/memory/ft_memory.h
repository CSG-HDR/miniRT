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

#ifndef FT_MEMORY_H
# define FT_MEMORY_H

# include <stddef.h>

# include "ft_types.h"

/**
 * @brief find index of given byte if any
 *
 * @param mem haystack to find in
 * @param size size of mem
 * @param to_find needle to find
 * @param out result
 * @return true if found
 * @return false if not found
 */
bool	ft_memory_find(const void *mem, size_t size, char to_find, size_t *out);

void	ft_memory_zero(void *mem, size_t len);
void	*ft_memory_set(void *mem, int value, size_t len);
void	ft_memory_copy(void *dest, const void *source, size_t size);

void	*ft_memory_allocate(size_t count, size_t size);
void	*ft_memory_duplicate(const void *source, size_t size);

#endif
