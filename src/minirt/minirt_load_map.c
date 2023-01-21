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

#include "t_map_validate.h"
#include "wrap.h"
#include "ft_os_file.h"
#include "ft_json.h"
#include "t_map_parse.h"

t_minirt_load_map_error	minirt_load_map(const char *path, t_map **out)
{
	char *const	file_contents = ft_os_file_read(path);
	t_ft_json	json;

	if (!file_contents)
		return (MINIRT_LOAD_MAP_ERROR_READ_FILE);
	if (ft_json_parse(file_contents, &json))
	{
		wrap_free(file_contents);
		return (MINIRT_LOAD_MAP_ERROR_MALLOC);
	}
	wrap_free(file_contents);
	if (!json)
		return (MINIRT_LOAD_MAP_ERROR_INVALID_JSON_FORMAT);
	if (!t_map_validate(json))
		return (MINIRT_LOAD_MAP_ERROR_INVALID_RT_SCHEMA);
	if (t_map_parse(json, out))
	{
		ft_json_free(json);
		return (MINIRT_LOAD_MAP_ERROR_MALLOC);
	}
	ft_json_free(json);
	return (MINIRT_LOAD_MAP_ERROR_SUCCESS);
}
