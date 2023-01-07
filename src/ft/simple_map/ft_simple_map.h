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

#ifndef FT_SIMPLE_MAP_H
# define FT_SIMPLE_MAP_H

# include <stddef.h>

# include "ft_types.h"

# ifndef S_FT_SIMPLE_MAP_STATIC_DEFINED
#  define S_FT_SIMPLE_MAP_STATIC_DEFINED

typedef void	t_ft_simple_map_static;
typedef void	t_ft_simple_map_static_iterator;

# endif

# ifndef S_FT_SIMPLE_MAP_DYNAMIC_DEFINED
#  define S_FT_SIMPLE_MAP_DYNAMIC_DEFINED

typedef void	t_ft_simple_map_dynamic;

# endif

t_ft_simple_map_static	*new_ft_simple_map_static(
							size_t key_length);
void					ft_simple_map_static_free(
							t_ft_simple_map_static *self,
							void (*free_value)(void *value));
t_err					ft_simple_map_static_set(
							t_ft_simple_map_static *self,
							const void *key,
							void *value);
bool					ft_simple_map_static_get(
							t_ft_simple_map_static *self,
							const void *key,
							void **out);
bool					ft_simple_map_static_pop(
							t_ft_simple_map_static *self,
							const void *key,
							void **out);

t_ft_simple_map_dynamic	*new_ft_simple_map_dynamic(void);
void					ft_simple_map_dynamic_free(
							t_ft_simple_map_dynamic *self,
							void (*free_value)(void *value));
t_err					ft_simple_map_dynamic_set(
							t_ft_simple_map_dynamic *self,
							const void *key,
							size_t key_length,
							void *value);
bool					ft_simple_map_dynamic_get(
							t_ft_simple_map_dynamic *self,
							const void *key,
							size_t key_length,
							void **out);
bool					ft_simple_map_dynamic_pop(
							t_ft_simple_map_dynamic *self,
							const void *key,
							size_t key_length,
							void **out);

#endif
