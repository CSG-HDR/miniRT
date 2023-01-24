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

int		t_map_polynomial_plane_validate_next(
			int current, char c);
int		t_map_polynomial_plane_validate_start(
			char c);
int		t_map_polynomial_plane_validate_first_minus(
			char c);
int		t_map_polynomial_plane_validate_first_coefficient_digit_first(
			char c);
int		t_map_polynomial_plane_validate_first_coefficient_digit_repeat(
			char c);
int		t_map_polynomial_plane_validate_first_coefficient_dot(
			char c);
int		t_map_polynomial_plane_validate_first_coefficient_decimal(
			char c);
int		t_map_polynomial_plane_validate_first_x(
			char c);
int		t_map_polynomial_plane_validate_first_x_degree(
			char c);
int		t_map_polynomial_plane_validate_first_x_degree_digit_first(
			char c);
int		t_map_polynomial_plane_validate_first_x_degree_digit_repeat(
			char c);
int		t_map_polynomial_plane_validate_first_y(
			char c);
int		t_map_polynomial_plane_validate_first_y_degree(
			char c);
int		t_map_polynomial_plane_validate_first_y_degree_digit_first(
			char c);
int		t_map_polynomial_plane_validate_first_y_degree_digit_repeat(
			char c);
int		t_map_polynomial_plane_validate_first_z(
			char c);
int		t_map_polynomial_plane_validate_first_z_degree(
			char c);
int		t_map_polynomial_plane_validate_first_z_degree_digit_first(
			char c);
int		t_map_polynomial_plane_validate_first_z_degree_digit_repeat(
			char c);
int		t_map_polynomial_plane_validate_repeat_plus(
			char c);
int		t_map_polynomial_plane_validate_repeat_minus(
			char c);
int		t_map_polynomial_plane_validate_repeat_coefficient_digit_first(
			char c);
int		t_map_polynomial_plane_validate_repeat_coefficient_digit_repeat(
			char c);
int		t_map_polynomial_plane_validate_repeat_coefficient_dot(
			char c);
int		t_map_polynomial_plane_validate_repeat_coefficient_decimal(
			char c);
int		t_map_polynomial_plane_validate_repeat_x(
			char c);
int		t_map_polynomial_plane_validate_repeat_x_degree(
			char c);
int		t_map_polynomial_plane_validate_repeat_x_degree_digit_first(
			char c);
int		t_map_polynomial_plane_validate_repeat_x_degree_digit_repeat(
			char c);
int		t_map_polynomial_plane_validate_repeat_y(
			char c);
int		t_map_polynomial_plane_validate_repeat_y_degree(
			char c);
int		t_map_polynomial_plane_validate_repeat_y_degree_digit_first(
			char c);
int		t_map_polynomial_plane_validate_repeat_y_degree_digit_repeat(
			char c);
int		t_map_polynomial_plane_validate_repeat_z(
			char c);
int		t_map_polynomial_plane_validate_repeat_z_degree(
			char c);
int		t_map_polynomial_plane_validate_repeat_z_degree_digit_first(
			char c);
int		t_map_polynomial_plane_validate_repeat_z_degree_digit_repeat(
			char c);

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

t_err	t_map_polynomial_plane_parse_next(
			t_map_polynomial_plane_parse_state *state, char c);
t_err	t_map_polynomial_plane_parse_start(
			t_map_polynomial_plane_parse_state *state, char c);
t_err	t_map_polynomial_plane_parse_first_minus(
			t_map_polynomial_plane_parse_state *state, char c);
t_err	t_map_polynomial_plane_parse_first_coefficient_digit_first(
			t_map_polynomial_plane_parse_state *state, char c);
t_err	t_map_polynomial_plane_parse_first_coefficient_digit_repeat(
			t_map_polynomial_plane_parse_state *state, char c);
t_err	t_map_polynomial_plane_parse_first_coefficient_dot(
			t_map_polynomial_plane_parse_state *state, char c);
t_err	t_map_polynomial_plane_parse_first_coefficient_decimal(
			t_map_polynomial_plane_parse_state *state, char c);
t_err	t_map_polynomial_plane_parse_first_x(
			t_map_polynomial_plane_parse_state *state, char c);
t_err	t_map_polynomial_plane_parse_first_x_degree(
			t_map_polynomial_plane_parse_state *state, char c);
t_err	t_map_polynomial_plane_parse_first_x_degree_digit_first(
			t_map_polynomial_plane_parse_state *state, char c);
t_err	t_map_polynomial_plane_parse_first_x_degree_digit_repeat(
			t_map_polynomial_plane_parse_state *state, char c);
t_err	t_map_polynomial_plane_parse_first_y(
			t_map_polynomial_plane_parse_state *state, char c);
t_err	t_map_polynomial_plane_parse_first_y_degree(
			t_map_polynomial_plane_parse_state *state, char c);
t_err	t_map_polynomial_plane_parse_first_y_degree_digit_first(
			t_map_polynomial_plane_parse_state *state, char c);
t_err	t_map_polynomial_plane_parse_first_y_degree_digit_repeat(
			t_map_polynomial_plane_parse_state *state, char c);
t_err	t_map_polynomial_plane_parse_first_z(
			t_map_polynomial_plane_parse_state *state, char c);
t_err	t_map_polynomial_plane_parse_first_z_degree(
			t_map_polynomial_plane_parse_state *state, char c);
t_err	t_map_polynomial_plane_parse_first_z_degree_digit_first(
			t_map_polynomial_plane_parse_state *state, char c);
t_err	t_map_polynomial_plane_parse_first_z_degree_digit_repeat(
			t_map_polynomial_plane_parse_state *state, char c);
t_err	t_map_polynomial_plane_parse_repeat_plus(
			t_map_polynomial_plane_parse_state *state, char c);
t_err	t_map_polynomial_plane_parse_repeat_minus(
			t_map_polynomial_plane_parse_state *state, char c);
t_err	t_map_polynomial_plane_parse_repeat_coefficient_digit_first(
			t_map_polynomial_plane_parse_state *state, char c);
t_err	t_map_polynomial_plane_parse_repeat_coefficient_digit_repeat(
			t_map_polynomial_plane_parse_state *state, char c);
t_err	t_map_polynomial_plane_parse_repeat_coefficient_dot(
			t_map_polynomial_plane_parse_state *state, char c);
t_err	t_map_polynomial_plane_parse_repeat_coefficient_decimal(
			t_map_polynomial_plane_parse_state *state, char c);
t_err	t_map_polynomial_plane_parse_repeat_x(
			t_map_polynomial_plane_parse_state *state, char c);
t_err	t_map_polynomial_plane_parse_repeat_x_degree(
			t_map_polynomial_plane_parse_state *state, char c);
t_err	t_map_polynomial_plane_parse_repeat_x_degree_digit_first(
			t_map_polynomial_plane_parse_state *state, char c);
t_err	t_map_polynomial_plane_parse_repeat_x_degree_digit_repeat(
			t_map_polynomial_plane_parse_state *state, char c);
t_err	t_map_polynomial_plane_parse_repeat_y(
			t_map_polynomial_plane_parse_state *state, char c);
t_err	t_map_polynomial_plane_parse_repeat_y_degree(
			t_map_polynomial_plane_parse_state *state, char c);
t_err	t_map_polynomial_plane_parse_repeat_y_degree_digit_first(
			t_map_polynomial_plane_parse_state *state, char c);
t_err	t_map_polynomial_plane_parse_repeat_y_degree_digit_repeat(
			t_map_polynomial_plane_parse_state *state, char c);
t_err	t_map_polynomial_plane_parse_repeat_z(
			t_map_polynomial_plane_parse_state *state, char c);
t_err	t_map_polynomial_plane_parse_repeat_z_degree(
			t_map_polynomial_plane_parse_state *state, char c);
t_err	t_map_polynomial_plane_parse_repeat_z_degree_digit_first(
			t_map_polynomial_plane_parse_state *state, char c);
t_err	t_map_polynomial_plane_parse_repeat_z_degree_digit_repeat(
			t_map_polynomial_plane_parse_state *state, char c);

# define T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_ERROR -1

# define T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_START 0
// [1-9] FIRST_COEFFICIENT_DIGIT_FIRST
// - FIRST_MINUS
// x FIRST_X
// y FIRST_Y
// z FIRST_Z

# define T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_FIRST_MINUS 1
// [1-9] FIRST_COEFFICIENT_DIGIT_FIRST
// x FIRST_X
// y FIRST_Y
// z FIRST_Z

# define T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_FIRST_COEFFICIENT_DIGIT_FIRST 2
// [0-9] FIRST_COEFFICIENT_DIGIT_REPEAT
// . FIRST_COEFFICIENT_DOT
// x FIRST_X
// y FIRST_Y
// z FIRST_Z
// + REPEAT_PLUS
// - REPEAT_MINUS
// $ end

# define T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_FIRST_COEFFICIENT_DIGIT_REPEAT 3
// [0-9] FIRST_COEFFICIENT_DIGIT_REPEAT
// . FIRST_COEFFICIENT_DOT
// x FIRST_X
// y FIRST_Y
// z FIRST_Z
// + REPEAT_PLUS
// - REPEAT_MINUS
// $ end

# define T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_FIRST_COEFFICIENT_DOT 4
// [0-9] FIRST_COEFFICIENT_DECIMAL

# define T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_FIRST_COEFFICIENT_DECIMAL 5
// [0-9] FIRST_COEFFICIENT_DECIMAL
// x FIRST_X
// y FIRST_Y
// z FIRST_Z
// + REPEAT_PLUS
// - REPEAT_MINUS
// $ end

# define T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_FIRST_X 6
// ^ FIRST_X_DEGREE
// y FIRST_Y
// z FIRST_Z
// + REPEAT_PLUS
// - REPEAT_MINUS
// $ end

# define T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_FIRST_X_DEGREE 7
// [1-9] FIRST_X_DEGREE_DIGIT_FIRST

# define T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_FIRST_X_DEGREE_DIGIT_FIRST 8
// [0-9] FIRST_X_DEGREE_DIGIT_REPEAT
// y FIRST_Y
// z FIRST_Z
// + REPEAT_PLUS
// - REPEAT_MINUS
// $ end

# define T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_FIRST_X_DEGREE_DIGIT_REPEAT 9
// [0-9] FIRST_X_DEGREE_DIGIT_REPEAT
// y FIRST_Y
// z FIRST_Z
// + REPEAT_PLUS
// - REPEAT_MINUS
// $ end

# define T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_FIRST_Y 10
// ^ FIRST_Y_DEGREE
// z FIRST_Z
// + REPEAT_PLUS
// - REPEAT_MINUS
// $ end

# define T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_FIRST_Y_DEGREE 11
// [1-9] FIRST_Y_DEGREE_DIGIT_FIRST

# define T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_FIRST_Y_DEGREE_DIGIT_FIRST 12
// [0-9] FIRST_Y_DEGREE_DIGIT_REPEAT
// z FIRST_Z
// + REPEAT_PLUS
// - REPEAT_MINUS
// $ end

# define T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_FIRST_Y_DEGREE_DIGIT_REPEAT 13
// [0-9] FIRST_Y_DEGREE_DIGIT_REPEAT
// z FIRST_Z
// + REPEAT_PLUS
// - REPEAT_MINUS
// $ end

# define T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_FIRST_Z 14
// ^ FIRST_Z_DEGREE
// + REPEAT_PLUS
// - REPEAT_MINUS
// $ end

# define T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_FIRST_Z_DEGREE 15
// [1-9] FIRST_Z_DEGREE_DIGIT_FIRST

# define T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_FIRST_Z_DEGREE_DIGIT_FIRST 16
// [0-9] FIRST_Z_DEGREE_DIGIT_REPEAT
// + REPEAT_PLUS
// - REPEAT_MINUS
// $ end

# define T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_FIRST_Z_DEGREE_DIGIT_REPEAT 17
// [0-9] FIRST_Z_DEGREE_DIGIT_REPEAT
// + REPEAT_PLUS
// - REPEAT_MINUS
// $ end

# define T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_REPEAT_PLUS 18
// [1-9] REPEAT_COEFFICIENT_DIGIT_FIRST
// x REPEAT_X
// y REPEAT_Y
// z REPEAT_Z

# define T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_REPEAT_MINUS 19
// [1-9] REPEAT_COEFFICIENT_DIGIT_FIRST
// x REPEAT_X
// y REPEAT_Y
// z REPEAT_Z

# define T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_REPEAT_COEFFICIENT_DIGIT_FIRST 20
// [0-9] REPEAT_COEFFICIENT_DIGIT_REPEAT
// . REPEAT_COEFFICIENT_DOT
// x REPEAT_X
// y REPEAT_Y
// z REPEAT_Z
// + REPEAT_PLUS
// - REPEAT_MINUS
// $ end

# define T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_REPEAT_COEFFICIENT_DIGIT_REPEAT 21
// [0-9] REPEAT_COEFFICIENT_DIGIT_REPEAT
// . REPEAT_COEFFICIENT_DOT
// x REPEAT_X
// y REPEAT_Y
// z REPEAT_Z
// + REPEAT_PLUS
// - REPEAT_MINUS
// $ end

# define T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_REPEAT_COEFFICIENT_DOT 22
// [0-9] REPEAT_COEFFICIENT_DECIMAL

# define T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_REPEAT_COEFFICIENT_DECIMAL 23
// [0-9] REPEAT_COEFFICIENT_DECIMAL
// x REPEAT_X
// y REPEAT_Y
// z REPEAT_Z
// + REPEAT_PLUS
// - REPEAT_MINUS
// $ end

# define T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_REPEAT_X 24
// ^ REPEAT_X_DEGREE
// y REPEAT_Y
// z REPEAT_Z
// + REPEAT_PLUS
// - REPEAT_MINUS
// $ end

# define T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_REPEAT_X_DEGREE 25
// [1-9] REPEAT_X_DEGREE_DIGIT_FIRST

# define T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_REPEAT_X_DEGREE_DIGIT_FIRST 26
// [0-9] REPEAT_X_DEGREE_DIGIT_REPEAT
// y REPEAT_Y
// z REPEAT_Z
// + REPEAT_PLUS
// - REPEAT_MINUS
// $ end

# define T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_REPEAT_X_DEGREE_DIGIT_REPEAT 27
// [0-9] REPEAT_X_DEGREE_DIGIT_REPEAT
// y REPEAT_Y
// z REPEAT_Z
// + REPEAT_PLUS
// - REPEAT_MINUS
// $ end

# define T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_REPEAT_Y 28
// ^ REPEAT_Y_DEGREE
// z REPEAT_Z
// + REPEAT_PLUS
// - REPEAT_MINUS
// $ end

# define T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_REPEAT_Y_DEGREE 29
// [1-9] REPEAT_Y_DEGREE_DIGIT_FIRST

# define T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_REPEAT_Y_DEGREE_DIGIT_FIRST 30
// [0-9] REPEAT_Y_DEGREE_DIGIT_REPEAT
// z REPEAT_Z
// + REPEAT_PLUS
// - REPEAT_MINUS
// $ end

# define T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_REPEAT_Y_DEGREE_DIGIT_REPEAT 31
// [0-9] REPEAT_Y_DEGREE_DIGIT_REPEAT
// z REPEAT_Z
// + REPEAT_PLUS
// - REPEAT_MINUS
// $ end

# define T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_REPEAT_Z 32
// ^ REPEAT_Z_DEGREE
// + REPEAT_PLUS
// - REPEAT_MINUS
// $ end

# define T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_REPEAT_Z_DEGREE 33
// [1-9] REPEAT_Z_DEGREE_DIGIT_FIRST

# define T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_REPEAT_Z_DEGREE_DIGIT_FIRST 35
// [0-9] REPEAT_Z_DEGREE_DIGIT_REPEAT
// + REPEAT_PLUS
// - REPEAT_MINUS
// $ end

# define T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_REPEAT_Z_DEGREE_DIGIT_REPEAT 35
// [0-9] REPEAT_Z_DEGREE_DIGIT_REPEAT
// + REPEAT_PLUS
// - REPEAT_MINUS
// $ end

# define T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_END 36

#endif
