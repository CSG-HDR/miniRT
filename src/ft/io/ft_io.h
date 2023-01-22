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

#ifndef FT_IO_H
# define FT_IO_H

# include <stddef.h>
# include <stdint.h>

# include "ft_types.h"

t_err	ft_io_write(int fd, const void *buf, size_t len);
t_err	ft_io_read(int fd, void *buf, size_t len);

t_err	ft_io_puts(int fd, const char *str);

t_err	ft_io_le_write_u8(int fd, uint8_t u8);
t_err	ft_io_le_write_u16(int fd, uint16_t u16);
t_err	ft_io_le_write_u32(int fd, uint32_t u32);
t_err	ft_io_le_write_u64(int fd, uint64_t u32);
t_err	ft_io_le_read_u8(int fd, uint8_t *out_u8);
t_err	ft_io_le_read_u16(int fd, uint16_t *out_u16);
t_err	ft_io_le_read_u32(int fd, uint32_t *out_u32);
t_err	ft_io_le_read_u64(int fd, uint64_t *out_u32);
t_err	ft_io_be_write_u8(int fd, uint8_t u8);
t_err	ft_io_be_write_u16(int fd, uint16_t u16);
t_err	ft_io_be_write_u32(int fd, uint32_t u32);
t_err	ft_io_be_write_u64(int fd, uint64_t u32);
t_err	ft_io_be_read_u8(int fd, uint8_t *out_u8);
t_err	ft_io_be_read_u16(int fd, uint16_t *out_u16);
t_err	ft_io_be_read_u32(int fd, uint32_t *out_u32);
t_err	ft_io_be_read_u64(int fd, uint64_t *out_u32);

#endif
