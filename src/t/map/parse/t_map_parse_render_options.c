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

#include "t_map_parse.h"

#include "ft_json.h"
#include "t_f.h"
#include "t_f3.h"
#include "t_map.h"

void	t_map_parse_render_options(t_ft_json value, t_map_render_options *out)
{
	t_ft_json	options;

	t_map_parse_get_default_render_options(out);
	if (!ft_json_dict_has_key(value, "renderOptions"))
		return ;
	options = ft_json_get_dict(value, "renderOptions");
	if (ft_json_dict_has_key(options, "superSampling"))
		out->super_sampling = (size_t)ft_json_get_number(
				ft_json_get_dict(options, "superSampling"));
	if (ft_json_dict_has_key(options, "shadow"))
		out->shadow = ft_json_get_bool(ft_json_get_dict(options, "shadow"));
	if (ft_json_dict_has_key(options, "gamma"))
		out->gamma = ft_json_get_number(ft_json_get_dict(options, "gamma"));
	if (ft_json_dict_has_key(options, "exposure"))
		out->exposure
			= ft_json_get_number(ft_json_get_dict(options, "exposure"));
}
