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

#include <stdio.h>
#include <stdlib.h>

#include "ft/leak_test.h"
#include "ft_cstring_split.h"

#define BUFFER_SIZE 1024
#define TEST_COUNT 5
#define PARTIAL_SIZE 42

typedef struct s_ft_split_args
{
	const char	*str;
	const char	*set;
}	t_ft_split_args;

static const t_ft_split_args	g_test_cases[] = {
{"Hello world!", " "},
{"Hello, world!", ","},
{"Hello, world!", ", "},
{"Hello, world!\n", " "},
{"Hello, world!\n", ", "},
{"Hello, world!\n", "!\n"},
{"   Hello,   world!", " "},
};

static bool	testee(const t_ft_split_args *args)
{
	char	**result;

	leak_test_start();
	result = ft_cstring_split(args->str, args->set);
	if (result)
		ft_cstring_split_free(result);
	leak_test_end();
	return (false);
}

static int	tester(const char *str, const char *set)
{
	const t_ft_split_args	args = {str, set};
	const int				result
		= leak_test((t_leak_test)(&testee), &args, NULL);

	if (result != FT_LEAK_TEST_RESULT_OK)
	{
		printf("Failed on \"%s\" (%s): %s\n",
			args.set, args.str, leak_test_error(result));
		return (1);
	}
	return (0);
}

int	main(void)
{
	int		has_error;
	size_t	i;

	has_error = 0;
	i = -1;
	while (++i < sizeof(g_test_cases) / sizeof(t_ft_split_args))
		has_error |= tester(g_test_cases[i].str, g_test_cases[i].set);
	if (has_error)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
