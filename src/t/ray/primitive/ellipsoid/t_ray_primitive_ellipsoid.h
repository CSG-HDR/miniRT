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

#ifndef T_RAY_PRIMITIVE_ELLIPSOID_H
# define T_RAY_PRIMITIVE_ELLIPSOID_H

# include "ft_types.h"
# include "t_map.h"
# include "t_ray.h"

t_err	t_ray_primitive_ellipsoid_record(
			t_ray ray,
			t_map_ellipsoid ellipsoid,
			t_ray_hit_records_builder *builder);

#endif
