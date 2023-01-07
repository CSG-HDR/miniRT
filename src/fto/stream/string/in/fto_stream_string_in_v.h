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

#ifndef FTO_STREAM_STRING_IN_V_H
# define FTO_STREAM_STRING_IN_V_H

# include "fto_stream_string_in.h"

t_err	fto_stream_string_in_v_read_all(
			t_fto_stream_string_in *self,
			char *buffer,
			size_t length,
			size_t *read_bytes);
bool	fto_stream_string_in_v_end(
			t_fto_stream_string_in *self);
void	fto_stream_string_in_v_free(
			t_fto_stream_string_in *self);
void	fto_stream_string_in_v_reset(
			t_fto_stream_string_in *self,
			const char *string,
			bool string_owned);

#endif
