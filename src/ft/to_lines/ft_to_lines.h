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

#ifndef FT_TO_LINES_H
# define FT_TO_LINES_H

# include "ft_stringbuilder.h"

typedef struct s_ft_to_lines {
	t_stringbuilder	*current;
	const char		*pending;
	size_t			pending_offset;
	size_t			pending_length;
	size_t			buffer_size;
}	t_ft_to_lines;

/**
 * @brief initialize ft_to_lines context
 *
 * @param context address to store context
 * @param buffer_size new buffer size
 */
void	ft_to_lines_init(
			t_ft_to_lines *context,
			size_t buffer_size);

/**
 * @brief get line from context
 *
 * @param context data contains previous read data
 * @param out_line out parameter to get result
 * @param out_line_length required if the line contains null characters
 * @return true on error
 *
 * @remarks all data is drained when not error and (*out_line) is NULL
 * @see the data can be added by ft_to_lines_feed
 */
t_err	ft_to_lines_drain(
			t_ft_to_lines *context,
			char **out_line,
			size_t *out_line_length);

/**
 * @brief add temporary data to context, when no temporary data remains
 *
 * @param context data contains previous read data
 * @param append address of temporary data, maybe from wrap_read()
 * @param append_length length of append
 * @return true on error (error if data not drained before call)
 *
 * @warning append MUST NOT FREED before drain all data by ft_to_lines_drain
 * @see ft_to_lines_drain
 */
t_err	ft_to_lines_feed(
			t_ft_to_lines *context,
			const void *append,
			size_t append_length);

/**
 * @brief get current *incomplete* line (may useful to get last line)
 *
 * @param context data contains previous read data
 * @param out_line out parameter to get result, only if not NULL
 * @param out_line_length required if the line contains null characters
 * @return true on error
 */
t_err	ft_to_lines_get_current_line(
			t_ft_to_lines *context,
			char **out_line,
			size_t *out_line_length);

/**
 * @brief release all resources associated with context
 *
 * @param context data contains previous read data
 */
void	ft_to_lines_free(
			t_ft_to_lines *context);

#endif
