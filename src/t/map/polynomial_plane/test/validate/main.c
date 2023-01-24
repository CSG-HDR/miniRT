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
#include <string.h>

#include "ft_types.h"
#include "t_map_polynomial_plane.h"

static t_err	read_file_contents(const char *filename, char **out)
{
	FILE *const		fp = fopen(filename, "rb");
	unsigned long	length;
	bool			error;

	length = 0;
	error = !fp;
	*out = NULL;
	if (!error && fseek(fp, 0, SEEK_END))
		error = true;
	if (!error)
		length = ftell(fp);
	if (!error && fseek(fp, 0, SEEK_SET))
		error = true;
	if (!error)
		*out = malloc(length + 1);
	if (!*out)
		error = true;
	if (!error && fread(*out, 1, length, fp) != length)
		error = true;
	if (fp)
		fclose(fp);
	if (error)
		free(*out);
	(*out)[length] = '\0';
	return (error);
}

int	main(int argc, char **argv)
{
	char		*file_contents;
	const char	*line;

	if (argc < 2 || read_file_contents(argv[1], &file_contents))
		return (EXIT_FAILURE);
	line = strtok(file_contents, "\n");
	while (line)
	{
		if (t_map_polynomial_plane_validate(line))
		{
			if (puts("valid") == EOF)
				return (EXIT_FAILURE);
		}
		else
		{
			if (puts("invalid") == EOF)
				return (EXIT_FAILURE);
		}
		line = strtok(NULL, "\n");
	}
	free(file_contents);
}
