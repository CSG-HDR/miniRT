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

#ifndef FTO_STREAM_STRING_OUT_V_H
# define FTO_STREAM_STRING_OUT_V_H

# include "fto_stream_string_out.h"

t_err	fto_stream_string_out_v_write(
			t_fto_stream_string_out *self,
			const char *buffer,
			size_t length,
			size_t *wrote_bytes);
void	fto_stream_string_out_v_free_without_flush(
			t_fto_stream_string_out *self);
char	*fto_stream_string_out_v_to_string(
			t_fto_stream_string_out *self,
			size_t *length);

#endif
