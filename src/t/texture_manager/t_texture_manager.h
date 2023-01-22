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

#ifndef T_TEXTURE_MANAGER_H
# define T_TEXTURE_MANAGER_H

# include <stddef.h>

# include "t_image.h"
# include "t_map.h"

// TODO: use balanced BST or HashTable based data structure

typedef struct s_texture_manager_node
{
	struct s_texture_manager_node	*next;
	char							*path;
	t_image							*image;
}	t_texture_manager_node;

typedef struct s_texture_manager
{
	t_texture_manager_node	*head;
	t_texture_manager_node	*tail;
}	t_texture_manager;

t_texture_manager	*t_texture_manager_new(void);
void				t_texture_manager_free(t_texture_manager *self);
t_err				t_texture_manager_preload(
						t_texture_manager *self, const char *path);
t_err				t_texture_manager_preload_all(
						t_texture_manager *self, t_map *map);
t_image				*t_texture_manager_get(
						t_texture_manager *self, const char *path);

#endif
