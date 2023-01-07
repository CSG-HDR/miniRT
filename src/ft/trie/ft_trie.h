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

#ifndef FT_TRIE_H
# define FT_TRIE_H

# include <stddef.h>
# include <limits.h>

# include "ft_types.h"

typedef struct s_ft_trie_node
{
	void				*value;
	struct s_ft_trie	*parent;
	struct s_ft_trie	*child[1 << CHAR_BIT];
	size_t				depth;
	char				path[];
}	t_ft_trie_node;

typedef struct s_ft_trie
{
	t_ft_trie_node	*root;
}	t_ft_trie;

typedef struct s_ft_trie_key
{
	const void	*key;
	size_t		key_length;
}	t_ft_trie_key;

typedef t_err	(*t_ft_trie_iterate)(
					void *context,
					t_ft_trie *self,
					t_ft_trie_key *key,
					void *value);

t_ft_trie	*new_ft_trie(void);
t_err		ft_trie_push(
				t_ft_trie *self,
				const t_ft_trie_key *key,
				void *value,
				void **out_previous_value);
bool		ft_trie_has(
				t_ft_trie *self,
				const t_ft_trie_key *key);
bool		ft_trie_get(
				t_ft_trie *self,
				const t_ft_trie_key *key,
				void **out_value);
bool		ft_trie_pop(
				t_ft_trie *self,
				const t_ft_trie_key *key,
				void **out_value);
t_err		*ft_trie_iterate(
				t_ft_trie *self,
				t_ft_trie_iterate iterate);
void		ft_trie_unsafe_free(
				t_ft_trie *self);

#endif
