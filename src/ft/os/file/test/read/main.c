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

#include "ft_os_file.h"

int	main(int argc, char **argv)
{
	char	*read;

	if (argc < 2)
		return (EXIT_FAILURE);
	read = ft_os_file_read(argv[1], NULL);
	if (!read)
		return (EXIT_FAILURE);
	printf("%s\n", read);
	free(read);
	return (EXIT_SUCCESS);
}
