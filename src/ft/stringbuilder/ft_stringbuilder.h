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

#ifndef FT_STRINGBUILDER_H
# define FT_STRINGBUILDER_H

# include <stddef.h>

# include "ft_types.h"

typedef struct s_stringbuilder_node
{
	struct s_stringbuilder_node	*next;
	size_t						capacity;
	size_t						length;
	char						str[];
}	t_stringbuilder_node;

typedef struct s_stringbuilder
{
	size_t					length;
	t_stringbuilder_node	*head;
	t_stringbuilder_node	*tail;
	size_t					buffer_size;
}	t_stringbuilder;

t_stringbuilder	*new_stringbuilder(
					size_t buffer_size);
void			stringbuilder_free(
					t_stringbuilder *self);
t_err			stringbuilder_append(
					t_stringbuilder *self,
					size_t length,
					const char *buf);
t_err			stringbuilder_append_char(
					t_stringbuilder *self,
					char c);
t_err			stringbuilder_append_string(
					t_stringbuilder *self,
					const char *str);
char			*stringbuilder_to_string(
					t_stringbuilder *self,
					size_t offset);

#endif
