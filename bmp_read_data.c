/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_read_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcals <fcals@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 10:53:01 by fcals             #+#    #+#             */
/*   Updated: 2020/01/03 10:53:02 by fcals            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libbmp.h>

int	bmp_read_data(int fd, t_bmp *bmp)
{
	if (bmp->image_header.bit_count == 1 || bmp->image_header.bit_count == 4
		|| bmp->image_header.bit_count == 8)
	{
		if (bmp_read_palette(fd, bmp) == 0 &&
		bmp_read_data_palette(fd, bmp) == 0)
			return (0);
	}
	else if (bmp->image_header.bit_count == 16 ||
		bmp->image_header.bit_count == 24)
	{
		if (bmp_read_data_rgb(fd, bmp) == 0)
			return (0);
	}
	return (-1);
}
