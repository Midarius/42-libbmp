#include <libbmp.h>
#include <stdio.h>

static unsigned int	bmp_get_padding_byte(t_bmp *bmp)
{
	return (((((bmp->image_header.bit_count * bmp->image_header.width + 31) /
	32) * 4) * (8 / bmp->image_header.bit_count) - bmp->image_header.width) /
	(8 / bmp->image_header.bit_count));
}

int	bmp_read_data_rgb(int fd, t_bmp *bmp)
{
	unsigned int i;
	unsigned int j;
	unsigned int padding;
	unsigned char data_pxl;
	t_bmp_data_rgba *it;

	//padding dégeu a recoder
	padding = bmp->image_header.width % 4;
	printf("padding %u\n", padding);
	if (!(bmp->data_rgb = malloc(sizeof(t_bmp_data_rgba) *
	(bmp->image_header.width * bmp->image_header.height))))
		return (-1);
	i = 0;
	while (i < bmp->image_header.height)
	{
		j = 0;
		while (j < bmp->image_header.width)
		{
			it = &(bmp->data_rgb[j + (i * bmp->image_header.width)]);
			if (bmp->image_header.bit_count == 24)
			{
				if (ft_readequ(fd, &(it->blue), sizeof(unsigned char)) < 1 ||
				ft_readequ(fd, &(it->green), sizeof(unsigned char)) < 1 ||
				ft_readequ(fd, &(it->red), sizeof(unsigned char)) < 1)
					return (-1);
				j++;
			}
	// 		else if (bmp->image_header.bit_count == 16)
			// {
			// 	if (ft_readequ(fd, &data_pxl, sizeof(unsigned char)) < 1)
			// 		return (-1);
			// 	it->blue = data_pxl & 240;
			// 	it->green = data_pxl & 15;
			// 	if (ft_readequ(fd, &data_pxl, sizeof(unsigned char)) < 1)
			// 		return (-1);
			// 	it->red = data_pxl & 240;
			// 	it->alpha = data_pxl & 15;
			// 	j++;
			// }
		}
		i++;
		ft_read_skip(fd, padding);
	}
	return (0);
}
