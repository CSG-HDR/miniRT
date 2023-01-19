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

#ifndef FT_JSON_H
# define FT_JSON_H

# include <stddef.h>
# include <stdbool.h>

# include "ft_types.h"

typedef void	*t_ft_json;

t_err		ft_json_parse(const char *str, t_ft_json *out);
void		ft_json_free(t_ft_json value);

bool		ft_json_is_null(t_ft_json value);
bool		ft_json_is_boolean(t_ft_json value);
bool		ft_json_is_number(t_ft_json value);
bool		ft_json_is_string(t_ft_json value);
bool		ft_json_is_list(t_ft_json value);
bool		ft_json_is_dict(t_ft_json value);

size_t		ft_json_list_length(t_ft_json value);
bool		ft_json_dict_has_key(t_ft_json value, const char *key);

bool		ft_json_get_bool(t_ft_json value);
double		ft_json_get_number(t_ft_json value);
const char	*ft_json_get_string(t_ft_json value);
t_ft_json	ft_json_get_list(t_ft_json value, size_t index);
t_ft_json	ft_json_get_dict(t_ft_json value, const char *key);

#endif
