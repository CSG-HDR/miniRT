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

#include "t_map_free.h"

#include <stdbool.h>
#include <stdlib.h>

#include "wrap.h"
#include "t_map.h"
#include "t_map_free.h"

void	t_map_free(t_map *out)
{
	t_map_free_models(out->models, out->model_count);
	t_map_free_lights(out->lights, out->light_count);
	free(out);
}
