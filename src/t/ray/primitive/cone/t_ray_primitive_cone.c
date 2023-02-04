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

#include "t_ray.h"

#include "ft_types.h"
#include "t_map.h"
#include "t_ray_primitive_cone.h"

t_err	t_ray_primitive_cone(
	t_ray ray,
	t_map_cone cone,
	t_ray_hit_records *out
)
{
	t_ray_hit_records_builder	*builder;
	t_err						result;

	if (t_ray_hit_records_builder_init(&builder))
		return (true);
	if (t_ray_primitive_cone_side(ray, cone, builder))
	{
		t_ray_hit_records_builder_free(builder);
		return (true);
	}
	if (t_ray_primitive_cone_bottom(ray, cone, builder))
	{
		t_ray_hit_records_builder_free(builder);
		return (true);
	}
	if (builder->count != 0 && builder->count != 2)
	{
		t_ray_hit_records_builder_free(builder);
		*out = (t_ray_hit_records){0, NULL};
		return (false);
	}
	result = t_ray_hit_records_builder_build(builder, out);
	t_ray_hit_records_builder_free(builder);
	return (result);
}
