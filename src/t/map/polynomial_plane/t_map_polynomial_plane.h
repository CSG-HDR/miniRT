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

bool	t_map_polynomial_plane_validate(const char *str);
t_err	t_map_polynomial_plane_parse(
			const char *str, t_map_polynomial_plane **out);

typedef struct s_map_polynomial_plane_parse_state_node
{
	struct s_map_polynomial_plane_parse_state_node	*next;
	t_map_monomial									monomial;
}	t_map_polynomial_plane_parse_state_node;

typedef struct s_map_polynomial_plane_parse_state
{
	int										state;
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
