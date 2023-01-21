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

#include "minirt.h"

void	minirt_load_map_die(t_minirt_load_map_error error)
{
	if (error == MINIRT_LOAD_MAP_ERROR_READ_FILE)
		minirt_die("Error: failed to load scene file");
	if (error == MINIRT_LOAD_MAP_ERROR_INVALID_JSON_FORMAT)
		minirt_die("Error: given file is not a valid json file");
	if (error == MINIRT_LOAD_MAP_ERROR_INVALID_RT_SCHEMA)
		minirt_die("Error: given file is not a valid .rt format");
	if (error == MINIRT_LOAD_MAP_ERROR_MALLOC)
		minirt_die("Error: failed to allocate memory for load map");
}
