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

#ifndef MALLOC_MOCK_H
# define MALLOC_MOCK_H

# include <stddef.h>
# include <stdbool.h>

typedef struct s_malloc_mock
{
	void	*(*malloc_mock)(size_t, void *(*real)(size_t), void *context);
	void	(*free_mock)(void *, void (*real)(void *), void *context);
}	t_malloc_mock;

void	malloc_mock(const t_malloc_mock *mock, void *context);

#endif
