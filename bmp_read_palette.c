/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_read_palette.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcals <fcals@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 10:53:13 by fcals             #+#    #+#             */
/*   Updated: 2020/01/03 11:03:11 by fcals            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libbmp.h>

int	bmp_read_palette(int fd, t_bmp *bmp)
{
	unsigned int i;

	bmp->palette = malloc(sizeof(t_rgb_color) * bmp->image_header.color_used);
	i = 0;
	while (i < bmp->image_header.color_used)
	{
		if (ft_readequ(fd, &(bmp->palette[i].blue), sizeof(unsigned char)) < 1
		|| ft_readequ(fd, &(bmp->palette[i].green), sizeof(unsigned char)) < 1
		|| ft_readequ(fd, &(bmp->palette[i].red), sizeof(unsigned char)) < 1 ||
		ft_readequ(fd, &(bmp->palette[i].reserved), sizeof(unsigned char)) < 1)
			return (-1);
		i++;
	}
	return (0);
}
