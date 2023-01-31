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

#include "wrap.h"
#include "ft_types.h"
#include "t_f.h"
#include "t_map.h"

/**
 * f(x, y, z) = x^2/a^2 + y^2/b^2 + z^2/c^2 - 1 = 0
 * f(ray.position + ray.direction * distance) = 0
 * f(p+ut, q+vt, r+wt) = 0
 *
 * A = 1/a^2, B = 1/b^2, C = 1/c^2
 * Ax^2 + By^2 + Cz^2 - 1 = 0
 * Ap^2 + 2Aput + Au^2t^2 + Bq^2 + 2Bqvt + Bv^2t^2 + Cr^2 + 2Crwt + Cw^2t^2 -1=0
 * X = Au^2 + Bv^2 + Cw^2
 * Y = 2Apu + 2Bqv + 2Crw
 * Z = Ap^2 + Bq^2 + Cr^2 - 1
 * t = (-Y +- sqrt(Y^2 - 4XZ)) / 2X
 */
typedef struct s_locals
{
	t_f		a;
	t_f		b;
	t_f		c;
	t_f		p;
	t_f		q;
	t_f		r;
	t_f		u;
	t_f		v;
	t_f		w;
	t_f		x;
	t_f		y;
	t_f		z;
	t_f		y2_4xz;
	bool	hit;
	bool	has_record;
	bool	in_sphere;
	t_f		sqrt_y2_4xz;
}	t_locals;

t_locals	s_locals(t_ray ray, t_map_ellipsoid ellipsoid)
{
	t_locals	l;

	l.a = 1 / (ellipsoid.size.x * ellipsoid.size.x);
	l.b = 1 / (ellipsoid.size.y * ellipsoid.size.y);
	l.c = 1 / (ellipsoid.size.z * ellipsoid.size.z);
	l.p = ray.origin.x;
	l.q = ray.origin.y;
	l.r = ray.origin.z;
	l.u = ray.direction.x;
	l.v = ray.direction.y;
	l.w = ray.direction.z;
	l.x = (l.a * l.u * l.u) + (l.b * l.v * l.v) + (l.c * l.w * l.w);
	l.y = (2 * l.a * l.p * l.u) + (2 * l.b * l.q * l.v) + (2 * l.c * l.r * l.w);
	l.z = (l.a * l.p * l.p) + (l.b * l.q * l.q) + (l.c * l.r * l.r) - 1;
	l.y2_4xz = l.y * l.y + 4 * l.x * l.z;
	l.hit = l.y2_4xz > 0;
	l.has_record = (l.hit && (l.y < l.sqrt_y2_4xz));
	if (l.hit)
		l.sqrt_y2_4xz = t_f_sqrt(l.y2_4xz);
	l.in_sphere = (l.has_record && (-l.y - l.sqrt_y2_4xz < 0));
	return (l);
}

t_err	allocate(t_ray ray, const t_locals *l, t_ray_hit_records *out)
{
	t_ray_hit_record *const	result
		= wrap_malloc(sizeof(t_ray_hit_record) * 2);

	if (!result)
		return (true);
	out->hit_record_count = 2;
	out->hit_records = result;
	// TODO:
}

t_err	t_ray_primitive_ellipsoid(
	t_ray ray,
	t_map_ellipsoid ellipsoid,
	t_ray_hit_records *out
)
{
	const t_locals	l = s_locals(ray, ellipsoid);

	if (l.y2_4xz < 0 || l.y - l.sqrt_y2_4xz > 0)
	{
		*out = (t_ray_hit_records){0, NULL};
		return (false);
	}
	if (allocate(ray, &l, out))
		return (true);
	return (false);
}
