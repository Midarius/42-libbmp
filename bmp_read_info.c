/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_read_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcals <fcals@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 10:53:08 by fcals             #+#    #+#             */
/*   Updated: 2020/01/03 10:53:11 by fcals            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libbmp.h>
#include <stdio.h>

int	bmp_read_info(int fd, t_bmp *bmp)
{
	printf("%s\n", __func__);
	if (ft_readequ(fd, &(bmp->image_info.type), sizeof(unsigned short)) < 1 ||
	ft_readequ(fd, &(bmp->image_info.file_size), sizeof(unsigned int)) < 1 ||
	ft_readequ(fd, &(bmp->image_info.reserved1), sizeof(unsigned short)) < 1 ||
	ft_readequ(fd, &(bmp->image_info.reserved2), sizeof(unsigned short)) < 1 ||
	ft_readequ(fd, &(bmp->image_info.offset), sizeof(unsigned int)) < 1)
		return (-1);
	return (0);
}
