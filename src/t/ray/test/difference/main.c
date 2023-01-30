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
#include "t_f.h"
#include "t_ray.h"

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

static t_err	feed_record(
	t_ray_hit_records_builder *builder,
	const char *line
)
{
	double				distance;
	int					is_front_face;
	double				x;
	double				y;
	t_ray_hit_record	record;

	if (sscanf(line, "%lf %d %lf %lf", &distance, &is_front_face, &x, &y) != 4)
		return (true);
	record.distance = (t_f)distance;
	record.is_front_face = !!is_front_face;
	record.x = (t_f)x;
	record.y = (t_f)y;
	if (t_ray_hit_records_builder_add(builder, record))
		return (true);
	return (false);
}

static t_err	feed_records(
	char *line,
	t_ray_hit_records *out
)
{
	char						*part;
	t_ray_hit_records_builder	*builder;
	char						*olds;

	if (t_ray_hit_records_builder_init(&builder))
		return (true);
	part = strtok_r(line, "/", &olds);
	while (part)
	{
		if (feed_record(builder, part))
			return (true);
		part = strtok_r(NULL, "/", &olds);
	}
	if (t_ray_hit_records_builder_build(builder, out))
	{
		t_ray_hit_records_builder_free(builder);
		return (true);
	}
	t_ray_hit_records_builder_free(builder);
	return (false);
}

static t_err	print(t_ray_hit_records records)
{
	size_t		i;
	const char	*bool_name;

	i = -1;
	while (++i < records.hit_record_count)
	{
		bool_name = "false";
		if (records.hit_records[i].is_front_face)
			bool_name = "true";
		if (printf(
				"%lf %s %lf %lf\n",
				(double)records.hit_records[i].distance,
				bool_name,
				(double)records.hit_records[i].x,
				(double)records.hit_records[i].y
			) < 0)
			return (true);
	}
	return (false);
}

int	main(int argc, char **argv)
{
	char				*file_contents;
	char				*line;
	t_ray_hit_records	records;
	t_ray_hit_records	*array;
	size_t				array_length;

	if (argc < 2 || read_file_contents(argv[1], &file_contents))
		return (EXIT_FAILURE);
	line = strtok(file_contents, "\n");
	array = NULL;
	array_length = 0;
	while (line)
	{
		array_length++;
		array = realloc(array, sizeof(t_ray_hit_records) * array_length);
		if (!array || feed_records(line, &array[array_length - 1]))
			return (EXIT_FAILURE);
		line = strtok(NULL, "\n");
	}
	free(file_contents);
	if (array_length != 2
		|| t_ray_difference(array[0], array[1], &records) || print(records))
		return (EXIT_FAILURE);
	free(array);
	t_ray_hit_records_free(records);
}
