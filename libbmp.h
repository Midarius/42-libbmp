/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libbmp.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcals <fcals@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 10:55:59 by fcals             #+#    #+#             */
/*   Updated: 2020/01/03 10:57:57 by fcals            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBBMP_H
# define LIBBMP_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include <libbmp_def.h>
# include <libbmp_util.h>

t_bmp			*bmp_read(const char *path);
int				bmp_read_info(int fd, t_bmp *bmp);
int				bmp_read_header(int fd, t_bmp *bmp);
int				bmp_read_unused(int fd, t_bmp *bmp);
int				bmp_read_palette(int fd, t_bmp *bmp);
int				bmp_read_data(int fd, t_bmp *bmp);
int				bmp_read_data_palette(int fd, t_bmp *bmp);
int				bmp_read_data_rgb(int fd, t_bmp *bmp);
// unsigned int	bmp_get_padding_byte(t_bmp *bmp);
void			bmp_delete(t_bmp *bmp);
// int	bmp_create(t_bmp *bmp, unsigned int width, unsigned int height, unsigned int mode);

#endif
