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

#include "t_map_validate.h"

#include <stdbool.h>

#include "ft_json.h"

bool	t_map_validate_position(t_ft_json value)
{
	return (
		true
		&& ft_json_is_list(value)
		&& ft_json_list_length(value) == 3
		&& ft_json_is_number(ft_json_get_list(value, 0))
		&& ft_json_is_number(ft_json_get_list(value, 1))
		&& ft_json_is_number(ft_json_get_list(value, 2))
	);
}
