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

#include "ft_types_char.h"

static const bool	g_t = true;
static const bool	g_f = false;

static const bool	g_map[256] = {
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0000 ~ 0007
	g_f, g_t, g_f, g_f, g_f, g_f, g_f, g_f, // 0010 ~ 0017
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0020 ~ 0027
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0030 ~ 0037
	g_t, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0040 ~ 0047
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0050 ~ 0057
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0060 ~ 0067
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0070 ~ 0077
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0100 ~ 0107
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0110 ~ 0117
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0120 ~ 0127
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0130 ~ 0137
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0140 ~ 0147
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0150 ~ 0157
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0160 ~ 0167
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0170 ~ 0177
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0200 ~ 0207
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0210 ~ 0217
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0220 ~ 0227
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0230 ~ 0237
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0240 ~ 0247
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0250 ~ 0257
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0260 ~ 0267
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0270 ~ 0277
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0300 ~ 0307
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0310 ~ 0317
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0320 ~ 0327
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0330 ~ 0337
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0340 ~ 0347
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0350 ~ 0357
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0360 ~ 0367
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0370 ~ 0377
};

bool	ft_types_char_blank(char c)
{
	return (g_map[(unsigned char)c]);
}
