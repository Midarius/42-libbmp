/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_init_header.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcals <fcals@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 10:52:49 by fcals             #+#    #+#             */
/*   Updated: 2020/01/03 10:52:50 by fcals            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libbmp.h>

int	bmp_init_header(t_bmp *bmp)
{
	if (bmp = NULL)
		return (-1);
	bmp->image_info.type = BM_MAGIC;
	bmp->image_info.file_size = 0;
	bmp->image_info.reserved = 0;
	bmp->image_info.reserved = 0;
	bmp->image_info.offset = 54;
	return (0);
}
