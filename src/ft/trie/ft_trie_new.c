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

#include "wrap.h"

#include "ft_trie.h"

t_ft_trie	*new_ft_trie(void)
{
	t_ft_trie *const	result = wrap_malloc(sizeof(t_ft_trie));

	if (!result)
		return (NULL);
	result->root = NULL;
	return (result);
}
