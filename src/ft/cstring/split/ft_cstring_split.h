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

#ifndef FT_CSTRING_SPLIT_H
# define FT_CSTRING_SPLIT_H

# include <stddef.h>

char	**ft_cstring_split(const char *str, const char *charset);
size_t	ft_cstring_split_count(const char *str, const char *charset);
void	ft_cstring_split_free(char	**null_terminated_strings);

#endif
