/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_read_unused.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcals <fcals@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 10:53:15 by fcals             #+#    #+#             */
/*   Updated: 2020/01/03 10:53:16 by fcals            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libbmp.h>

int	bmp_read_unused(int fd, t_bmp *bmp)
{
	unsigned int size;

	if (bmp->image_header.size < 40)
		return (-1);
	if (bmp->image_header.size == 40)
		return (0);
	size = bmp->image_header.size - 40;
	if (!(bmp->image_header.unused = malloc(sizeof(unsigned char) * size)))
		return (-1);
	ft_readequ(fd, bmp->image_header.unused, size);
	return (0);
}
