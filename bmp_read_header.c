/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_read_header.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcals <fcals@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 10:53:04 by fcals             #+#    #+#             */
/*   Updated: 2020/01/03 10:53:05 by fcals            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libbmp.h>

int	bmp_read_header(int fd, t_bmp *bmp)
{
	if (ft_readequ(fd, &(bmp->image_header.size), sizeof(unsigned int)) < 1 ||
	ft_readequ(fd, &(bmp->image_header.width), sizeof(unsigned int)) < 1 ||
	ft_readequ(fd, &(bmp->image_header.height), sizeof(unsigned int)) < 1 ||
	ft_readequ(fd, &(bmp->image_header.planes), sizeof(unsigned short)) < 1 ||
	ft_readequ(fd, &(bmp->image_header.bit_count), sizeof(unsigned short)) < 1
	|| ft_readequ(fd, &(bmp->image_header.compression), sizeof(unsigned int))
	< 1 ||
	ft_readequ(fd, &(bmp->image_header.size_image), sizeof(unsigned int)) < 1
	|| ft_readequ(fd, &(bmp->image_header.x_pixel_meter), sizeof(unsigned int))
	< 1 ||
	ft_readequ(fd, &(bmp->image_header.y_pixel_meter), sizeof(unsigned int))
	< 1 ||
	ft_readequ(fd, &(bmp->image_header.color_used), sizeof(unsigned int)) < 1
	||
	ft_readequ(fd, &(bmp->image_header.color_important), sizeof(unsigned int))
	< 1 || bmp_read_unused(fd, bmp) == -1)
		return (-1);
	return (0);
}
