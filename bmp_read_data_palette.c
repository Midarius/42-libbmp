#include <libbmp.h>
#include <stdio.h>

static unsigned int	bmp_get_padding_byte(t_bmp *bmp)
{
	return (((((bmp->image_header.bit_count * bmp->image_header.width + 31) /
	32) * 4) * (8 / bmp->image_header.bit_count) - bmp->image_header.width) /
	(8 / bmp->image_header.bit_count));
}

int	bmp_read_data_palette(int fd, t_bmp *bmp)
{
	unsigned int i;
	unsigned int j;
	unsigned int k;
	unsigned int padding;
	unsigned char data_pxl;

	padding = bmp_get_padding_byte(bmp);
	printf("padding %u\n", padding);
	if (!(bmp->data_palette = malloc(sizeof(t_bmp_data_palette) *
	(bmp->image_header.width * bmp->image_header.height))))
		return (-1);
	i = 0;
	while (i < bmp->image_header.height)
	{
		j = 0;
		while (j < bmp->image_header.width)
		{
			if (ft_readequ(fd, &data_pxl, sizeof(unsigned char)) < 1)
				return (-1);
			if (bmp->image_header.bit_count == 1)
			{
				k = 0;
				while (j < bmp->image_header.width && k < 8)
				{
					bmp->data_palette[j + (i * bmp->image_header.width)].data = data_pxl >> 7;
					bmp->data_palette[j + (i * bmp->image_header.width)].color = &(bmp->palette[data_pxl >> 7]);
					data_pxl <<= 1;
					j++;
					k++;
				}
			}
			else if (bmp->image_header.bit_count == 4)
			{
				k = 0;
				while (j < bmp->image_header.width && k < 2)
				{
					bmp->data_palette[j + (i * bmp->image_header.width)].data = data_pxl >> 4;
					bmp->data_palette[j + (i * bmp->image_header.width)].color = &(bmp->palette[data_pxl >> 4]);
					data_pxl <<= 4;
					j++;
					k++;
				}
			}
			else if (bmp->image_header.bit_count == 8)
			{
				bmp->data_palette[j + (i * bmp->image_header.width)].data = data_pxl;
				bmp->data_palette[j + (i * bmp->image_header.width)].color = &(bmp->palette[data_pxl]);
				j++;
			}
		}
		i++;
		ft_read_skip(fd, padding);
	}
	return (0);
}
