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

#ifndef T_MAP_POLYNOMIAL_PLANE_H
# define T_MAP_POLYNOMIAL_PLANE_H

# include <stdbool.h>

# include "ft_types.h"
# include "t_map.h"

typedef struct s_map_monomial
{
	t_f	coefficient;
	t_f	degree_of_x;
	t_f	degree_of_y;
	t_f	degree_of_z;
}	t_map_monomial;

typedef struct s_map_polynomial_plane
{
	size_t					monomial_count;
	t_map_monomial			*monomials;
	bool					negate;
	t_map_color_material	material;
}	t_map_polynomial_plane;

bool	t_map_polynomial_plane_validate(const char *str);
t_err	t_map_polynomial_plane_parse(
			const char *str, t_map_polynomial_plane **out);

size_t	t_map_polynomial_plane_validate_next_monomial_offset(const char *str);
bool	t_map_polynomial_plane_validate_has_coefficient(const char *str);
bool	t_map_polynomial_plane_validate_coefficient(const char *str);
size_t	t_map_polynomial_plane_validate_coefficient_size(const char *str);
bool	t_map_polynomial_plane_validate_has_x(const char *str);
bool	t_map_polynomial_plane_validate_x(const char *str);
size_t	t_map_polynomial_plane_validate_x_size(const char *str);
bool	t_map_polynomial_plane_validate_has_y(const char *str);
bool	t_map_polynomial_plane_validate_y(const char *str);
size_t	t_map_polynomial_plane_validate_y_size(const char *str);
bool	t_map_polynomial_plane_validate_has_z(const char *str);
bool	t_map_polynomial_plane_validate_z(const char *str);
size_t	t_map_polynomial_plane_validate_z_size(const char *str);
bool	t_map_polynomial_plane_validate_monomial(const char *str);
size_t	t_map_polynomial_plane_validate_monomial_size(const char *str);

typedef struct s_map_polynomial_plane_parse_state_node
{
	struct s_map_polynomial_plane_parse_state_node	*next;
	t_map_monomial									monomial;
}	t_map_polynomial_plane_parse_state_node;

typedef struct s_map_polynomial_plane_parse_state
{
	double									current_dight;
	bool									is_coefficient_minus;
	t_map_monomial							current;
	t_map_polynomial_plane_parse_state_node	*head;
	t_map_polynomial_plane_parse_state_node	*tail;
}	t_map_polynomial_plane_parse_state;

t_err	t_map_polynomial_plane_parse_state_init(
			t_map_polynomial_plane_parse_state **out);
void	t_map_polynomial_plane_parse_state_free(
			t_map_polynomial_plane_parse_state *state);
t_err	t_map_polynomial_plane_parse_state_commit(
			t_map_polynomial_plane_parse_state *state);
/**
 * @brief build t_map_polynomial_plane from state, EXCEPT FOR MATERIAL
 *
 * @warning material is not initialized
 */
t_err	t_map_polynomial_plane_parse_state_build(
			t_map_polynomial_plane_parse_state *in,
			t_map_polynomial_plane **out);

#endif
