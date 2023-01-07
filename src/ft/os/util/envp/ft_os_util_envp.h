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

#ifndef FT_OS_UTIL_ENVP_H
# define FT_OS_UTIL_ENVP_H

# include "ft_types.h"
# include "ft_simple_map.h"

extern const char *const *const	environ;

typedef struct s_ft_os_util_envp_builder
{
	t_ft_simple_map_static	*map;
}	t_ft_os_util_envp_builder;

t_ft_os_util_envp_builder	*new_ft_os_util_envp_builder(
								const char *const *environ);
t_ft_os_util_envp_builder	*ft_os_util_envp_builder_clone(
								const t_ft_os_util_envp_builder *builder);

char						**ft_os_util_envp_builder_free(
								t_ft_os_util_envp_builder *self);

t_err						ft_os_util_envp_builder_override(
								t_ft_os_util_envp_builder *self,
								const char *const *environ);
t_err						ft_os_util_envp_builder_override_entry(
								t_ft_os_util_envp_builder *self,
								const char *key,
								const char *value);
t_err						ft_os_util_envp_builder_override_builder(
								t_ft_os_util_envp_builder *self,
								const t_ft_os_util_envp_builder *builder);

char						**ft_os_util_envp_builder_build(
								t_ft_os_util_envp_builder *self);

char						*ft_os_util_envp_builder_get(
								t_ft_os_util_envp_builder *self,
								const char *key);

const char					*ft_os_util_envp_get(
								const char *const *environ,
								const char *key);

#endif
