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

#include "test.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	assert(bool must_be_true, const char *message)
{
	if (!must_be_true)
	{
		puts(message);
		exit(EXIT_FAILURE);
	}
}

void	assert_str_eq(char *actual, char *expected)
{
	assert(actual && expected, "One of string is NULL");
	if (strcmp(actual, expected) != 0)
	{
		printf(
			"Given two strings are not equal:\n\tactual: %s\n\texpected: %s\n",
			actual, expected);
		exit(EXIT_FAILURE);
	}
}

void	assert_null(void *must_be_null)
{
	assert(must_be_null == NULL, "Given value is not NULL");
}

void	assert_not_null(void *must_not_be_null)
{
	assert(must_not_be_null != NULL, "Given value is NULL");
}
