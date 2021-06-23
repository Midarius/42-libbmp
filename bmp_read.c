/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcals <fcals@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 10:53:20 by fcals             #+#    #+#             */
/*   Updated: 2020/01/03 10:53:20 by fcals            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libbmp.h>
#include <stdio.h>

t_bmp	*bmp_read(const char *path)
{
	int		fd;
	t_bmp	*bmp;

	printf("%s\n", __func__);
	if ((fd = open(path, O_RDONLY)) == -1)
		return (NULL);
	if (!(bmp = (t_bmp*)malloc(sizeof(t_bmp))))
		return (NULL);
	bmp->image_header.unused = NULL;
	bmp->palette = NULL;
	bmp->data_palette = NULL;
	bmp->data_rgb = NULL;
	if (bmp_read_info(fd, bmp) == -1 || bmp_read_header(fd, bmp) == -1 ||
	bmp_read_data(fd, bmp) == -1)
	{
		printf("error read\n");
		close(fd);
		bmp_delete(bmp);
		return (NULL);
	}
	close(fd);
	return (bmp);
}
