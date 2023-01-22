/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ray.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongyle <seongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:02:33 by seongyle          #+#    #+#             */
/*   Updated: 2023/01/22 20:09:59 by seongyle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_RAY_H
# define T_RAY_H

#include "t_f.h"
#include "t_f3.h"
#include <stdbool.h>

typedef struct s_ray
{
	t_f3	origin;
	t_f3	dir;
} t_ray;

typedef struct s_hit_record
{
	t_f3	point;
	t_f3	normal;
	t_f		t_min;
	t_f		t_max;
	t_f		t;
	bool	front_face;
	t_f3	albedo;
} t_hit_record;

#endif
