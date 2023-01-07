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

#ifndef MINIRT_HOOKS_H
# define MINIRT_HOOKS_H

# include "minirt.h"

# define MLX_EVENT_ON_KEYDOWN 2
# define MLX_EVENT_ON_KEYUP 3
# define MLX_EVENT_ON_MOUSE 4
# define MLX_EVENT_ON_MOUSE_MOVE 6
# define MLX_EVENT_ON_DESTROY 17

# define MLX_KEY_A 0
# define MLX_KEY_S 1
# define MLX_KEY_D 2
# define MLX_KEY_Q 12
# define MLX_KEY_W 13
# define MLX_KEY_E 14
# define MLX_KEY_R 15
# define MLX_KEY_ARROW_LEFT 123
# define MLX_KEY_ARROW_RIGHT 124
# define MLX_KEY_ARROW_DOWN 125
# define MLX_KEY_ARROW_UP 126
# define MLX_KEY_ESC 53

# define MLX_BUTTON_LEFT 1
# define MLX_BUTTON_RIGHT 2
# define MLX_BUTTON_MIDDLE 3
# define MLX_BUTTON_SCROLL_UP 4
# define MLX_BUTTON_SCROLL_DOWN 5

int	minirt_hooks_init(t_minirt *param);
int	minirt_hooks_exit(int unused, t_minirt *param);
int	minirt_hooks_key(int keycode, t_minirt *param);
int	minirt_hooks_mouse(int button, int x, int y, t_minirt *param);

#endif
