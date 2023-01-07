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

#include "ft_exit.h"

#include <stdbool.h>

#include "wrap.h"

static t_ft_exit_cleanup_function	x(
	bool get,
	t_ft_exit_cleanup_function new_cleanup_function
)
{
	static t_ft_exit_cleanup_function	cleanup_function = NULL;
	static bool							disabled = false;

	if (get && !disabled)
	{
		disabled = true;
		return (cleanup_function);
	}
	cleanup_function = new_cleanup_function;
	return (NULL);
}

int	ft_exit(signed char status)
{
	const t_ft_exit_cleanup_function	cleanup_function = x(true, NULL);

	if (cleanup_function)
		cleanup_function();
	wrap_exit((int) status);
	return (status);
}

void	ft_set_exit_handler(t_ft_exit_cleanup_function cleanup_function)
{
	x(false, cleanup_function);
}
