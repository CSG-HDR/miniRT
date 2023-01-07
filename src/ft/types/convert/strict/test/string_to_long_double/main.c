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

#include "ft_types_convert_strict.h"

int	main(int argc, char **argv)
{
	char		buffer[1024];
	long double	d;

	if (argc > 1)
		freopen(argv[1], "r", stdin);
	while (true)
	{
		if (scanf(" %1000[^\n]", buffer) != 1)
			break ;
		if (ft_types_convert_strict_string_to_long_double(buffer, &d))
			puts("invalid");
		else
			printf("%Lf\n", d);
	}
	if (!feof(stdin))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
