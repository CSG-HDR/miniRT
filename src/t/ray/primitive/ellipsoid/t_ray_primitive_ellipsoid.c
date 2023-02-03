/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ray_primitive_ellipsoid.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2023/02/04 01:07:50 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_ray.h"

#include "wrap.h"
#include "ft_types.h"
#include "t_f.h"
#include "t_f3.h"
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
	t_f				a;
	t_f				b;
	t_f				c;
	t_f				p;
	t_f				q;
	t_f				r;
	t_f				u;
	t_f				v;
	t_f				w;
	t_f				x;
	t_f				y;
	t_f				z;
	t_f				y2_4xz;
	bool			hit;
	bool			has_record;
	bool			in_ellipsoid;
	t_f				sqrt_y2_4xz;
	t_map_material	material;
}	t_locals;

static t_locals	s_locals(t_ray ray, t_map_ellipsoid ellipsoid)
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
	l.y2_4xz = l.y * l.y - 4 * l.x * l.z;
	l.hit = l.y2_4xz > 0;
	if (l.hit)
		l.sqrt_y2_4xz = t_f_sqrt(l.y2_4xz);
	l.has_record = (l.hit && (l.y < l.sqrt_y2_4xz));
	l.in_ellipsoid = (l.has_record && (-l.y - l.sqrt_y2_4xz < 0));
	l.material = ellipsoid.material;
	return (l);
}

static t_map_normal	normal(t_ray ray, const t_locals *l, t_f distance)
{
	(void)ray;
	(void)l;
	(void)distance;
	return ((t_map_normal){(t_f)0, (t_f)0, (t_f)0});
}

// TODO: implement
/**
 * @return t_f texture coord x
 */
static t_f	coord(t_ray ray, const t_locals *l, t_f distance, t_f *out_y)
{
	(void)ray;
	(void)l;
	(void)distance;
	(void)out_y;
	return (*out_y);
}

static t_err	allocate(t_ray ray, const t_locals *l, t_ray_hit_records *out)
{
	t_ray_hit_record *const	result = wrap_malloc(sizeof(t_ray_hit_record) * 2);

	if (!result)
		return (true);
	result[0] = (t_ray_hit_record){0, (t_map_normal){0, 0, 1},
		t_ray_material_from_color(l->material), true, 0, 0};
	if (!l->in_ellipsoid)
	{
		result[0].distance = (-l->y - l->sqrt_y2_4xz) / (2 * l->x);
		result[0].normal = normal(ray, l, result[0].distance);
		result[0].x = coord(ray, l, result[0].distance, &result[0].y);
	}
	result[1] = (t_ray_hit_record){0, (t_map_normal){0, 0, 1},
		t_ray_material_from_color(l->material), false, 0, 0};
	result[1].distance = (-l->y + l->sqrt_y2_4xz) / (2 * l->x);
	result[1].normal = normal(ray, l, result[1].distance);
	result[1].x = coord(ray, l, result[1].distance, &result[1].y);
	out->hit_record_count = 2;
	out->hit_records = result;
	return (false);
}

t_err	t_ray_primitive_ellipsoid(
	t_ray ray,
	t_map_ellipsoid ellipsoid,
	t_ray_hit_records *out
)
{
	const t_ray		preprocessed
		= t_ray_preprocess(ray, ellipsoid.position, ellipsoid.rotation);
	const t_locals	l = s_locals(preprocessed, ellipsoid);
	size_t			i;

	if (!l.hit)
	{
		*out = (t_ray_hit_records){0, NULL};
		return (false);
	}
	if (allocate(ray, &l, out))
		return (true);
	i = -1;
	while (++i < (*out).hit_record_count)
		(*out).hit_records[i].normal = t_f3_rotate(
				ellipsoid.rotation, (*out).hit_records[i].normal);
	return (false);
}
