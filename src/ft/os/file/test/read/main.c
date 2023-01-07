/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2023/01/07 17:24:38 by Juyeong Maing    ###   ########.fr       */
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
	read = ft_os_file_read(argv[1]);
	if (!read)
		return (EXIT_FAILURE);
	printf("%s\n", read);
	free(read);
	return (EXIT_SUCCESS);
}
