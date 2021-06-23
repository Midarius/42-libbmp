/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libbmp_util.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcals <fcals@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 10:57:18 by fcals             #+#    #+#             */
/*   Updated: 2020/01/03 10:57:41 by fcals            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBBMP_UTIL_H
# define LIBBMP_UTIL_H

# include <unistd.h>
# include <fcntl.h>

int	ft_readequ(int fd, void *buf, size_t count);
int	ft_read_skip(const int fd, unsigned int size);

#endif
