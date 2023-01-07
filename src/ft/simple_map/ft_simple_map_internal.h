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

#ifndef FT_SIMPLE_MAP_INTERNAL_H
# define FT_SIMPLE_MAP_INTERNAL_H

# include <stddef.h>
# include <stdbool.h>
# include <limits.h>

typedef union u_ft_simple_map_static_value
{
	void								*value[1 << CHAR_BIT];
	union u_ft_simple_map_static_value	*array[1 << CHAR_BIT];
}	t_ft_simple_map_static_value;

# define S_FT_SIMPLE_MAP_STATIC_DEFINED

typedef struct s_ft_simple_map_static
{
	size_t							key_length;
	t_ft_simple_map_static_value	*values;
}	t_ft_simple_map_static;

# define S_FT_SIMPLE_MAP_DYNAMIC_DEFINED

typedef struct s_ft_simple_map_dynamic
{
	void							*value;
	struct s_ft_simple_map_dynamic	*array[1 << CHAR_BIT];
}	t_ft_simple_map_dynamic;

typedef struct s_ft_simple_map_static_context_set
{
	t_ft_simple_map_static	*self;
	const void				*key;
	void					*value;
}	t_ft_simple_map_static_context_set;

typedef struct s_ft_simple_map_static_context_get
{
	t_ft_simple_map_static	*self;
	const void				*key;
	void					**out;
}	t_ft_simple_map_static_context_get;

#endif
