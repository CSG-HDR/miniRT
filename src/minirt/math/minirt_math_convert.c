#include "minirt_math.h"

t_vec3	minirt_math_convert_to_normal(t_vec3 rotate)
{
   		const double theta_x = 2 * M_PI * rotate.x;
		const double theta_y = 2 * M_PI * rotate.y;
		const double theta_z = 2 * M_PI * rotate.z;
		const t_vec3 norm = vec3(cos(theta_x), cos(theta_y), cos(theta_z));
		
		return (vunit(norm));
}
