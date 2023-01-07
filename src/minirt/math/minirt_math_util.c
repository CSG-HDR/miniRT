#include "minirt_math.h"
#include <stdbool.h>

double	vdot(t_vec3 vec, t_vec3 vec2)
{
	return (vec.x * vec2.x + vec.y * vec2.y + vec.z * vec2.z);
}

t_vec3	vcross(t_vec3 vec, t_vec3 vec2)
{
	t_vec3	new;

	new.x = vec.y * vec2.z - vec.z * vec2.y;
	new.y = vec.z * vec2.x - vec.x * vec2.z;
	new.z = vec.x * vec2.y - vec.y * vec2.x;
	return (new);
}

t_vec3	vmin(t_vec3 vec1, t_vec3 vec2)
{
	if (vec1.x > vec2.x)
		vec1.x = vec2.x;
	if (vec1.y > vec2.y)
		vec1.y = vec2.y;
	if (vec1.z > vec2.z)
		vec1.z = vec2.z;
	return (vec1);
}

static bool	vsame(t_vec3 vec1, t_vec3 vec2)
{
	if (vec1.x == vec2.x && vec1.y == vec2.y && vec1.z == vec2.z)
		return (true);
	return (false);
}

t_vec3	vup(t_vec3 vec)
{
	t_vec3	temp_vec;
	double	direct;

	if (vsame(vec, vec3(0, 1, 0)))
		return (vec3(-1, 0, 0));
	else if (vsame(vec, vec3(0, -1, 0)))
		return (vec3(1, 0, 0));
	else
	{
		temp_vec = vcross(vec, vec3(0, 1, 0));
		direct = vdot(temp_vec, vec3(0, 0, 1));
		if (direct < 0)
			return (vec3(0, -1, 0));
		return (vec3(0, 1, 0));
	}
}
