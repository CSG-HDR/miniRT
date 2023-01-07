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

#ifndef FTO_STREAM_OUT_V_H
# define FTO_STREAM_OUT_V_H

# include "fto_stream_out.h"

t_err	fto_stream_out_v_flush(
			t_fto_stream_out *self);
t_err	fto_stream_out_v_try_free(
			t_fto_stream_out *self);

#endif
