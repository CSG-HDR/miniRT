#include "minirt_math.h"

t_vec3	minirt_math_convert_to_normal(t_vec3 rotate)
{
	const double theta_x = 2 * M_PI * rotate.x;
	const double theta_y = 2 * M_PI * rotate.y;
	const double theta_z = 2 * M_PI * rotate.z;

	t_vec3 normal_vector = vec3(tan(theta_x), tan(theta_y), tan(theta_z));
	return (normal_vector);
}
