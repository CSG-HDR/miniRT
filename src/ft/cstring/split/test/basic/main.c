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

#include <stdlib.h>
#include <string.h>

#include "ft_cstring_split.h"
#include "test.h"

int	main(void)
{
	char **const	s1 = ft_cstring_split("Hello, world!\n", ", \n");
	char **const	s2 = ft_cstring_split("\fa\tb\r\nc\v", "\t\n\v\f\r ");

	assert_not_null(s1);
	assert_str_eq(s1[0], "Hello");
	assert_str_eq(s1[1], "world!");
	assert_null(s1[2]);
	ft_cstring_split_free(s1);
	assert_not_null(s2);
	assert_str_eq(s2[0], "a");
	assert_str_eq(s2[1], "b");
	assert_str_eq(s2[2], "c");
	assert_null(s2[3]);
	ft_cstring_split_free(s2);
}
