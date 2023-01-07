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

#include "ft_strict_atoi.h"

int	main(int argc, char **argv)
{
	char	buffer[1024];
	int		i;

	if (argc > 1)
		freopen(argv[1], "r", stdin);
	while (true)
	{
		if (scanf(" %1000[^\n]", buffer) != 1)
			break ;
		if (ft_strict_atoi(buffer, &i))
			puts("invalid");
		else
			printf("%d\n", i);
	}
	if (!feof(stdin))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
