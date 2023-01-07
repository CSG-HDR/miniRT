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

#include "ft_os_util_envp.h"

#include "ft_cstring.h"

const char	*ft_os_util_envp_get(
	const char *const *environ,
	const char *key
)
{
	size_t	i;

	while (environ && *environ)
	{
		environ++;
		if (ft_cstring_starts_with(*environ, key, &i) && (*environ)[i] == '=')
			return (*environ + i + 1);
	}
	return (NULL);
}
