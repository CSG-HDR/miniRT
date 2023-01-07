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

#ifndef WRAP_H
# define WRAP_H

# include <stddef.h>
# include <unistd.h>

void	*wrap_malloc(size_t size);
void	wrap_free(void *memory);
ssize_t	wrap_write(int fd, const void *buffer, size_t bytes);
ssize_t	wrap_read(int fd, void *buffer, size_t bytes);
void	wrap_exit(int status);
int		wrap_open(const char *path, int flags, ...);
int		wrap_close(int fd);
int		wrap_dup2(int source_fd, int new_fd);
int		wrap_pipe(int fds[2]);
pid_t	wrap_fork(void);
pid_t	wrap_wait(int *stat_loc);
pid_t	wrap_waitpid(pid_t pid, int *stat_loc, int options);
int		wrap_access(const char *pathname, int mode);
int		wrap_unlink(const char *path);

#endif
