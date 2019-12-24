#include <stdio.h>

#include <libbmp.h>

void	print_palette(t_bmp *img)
{
	unsigned int i;
	t_rgb_color	v;

	i = 0;
	while (i < img->image_header.color_used)
	{
		v = img->palette[i];
		printf("%i:\t[%u, %u, %u]\n", i, v.red, v.green, v.blue);
		i++;
	}
}

void	print_data_rgb(t_bmp *bmp, unsigned int size)
{
	unsigned int i;
	unsigned int j;
	t_bmp_data_rgba *it;

	i = 0;
	while (i < bmp->image_header.height && size)
	{
		j = 0;
		while (j < bmp->image_header.width && size)
		{
			it = &(bmp->data_rgb[j + (i * bmp->image_header.width)]);
			printf("%u, %u: [%u, %u, %u] ", j, i, it->red, it->green, it->blue);
			j++;
			size--;
		}
		printf("\n");
		i++;
	}
}

void	print_data_palette(t_bmp *bmp, unsigned int size)
{
	unsigned int i;
	unsigned int j;
	t_bmp_data_palette *it;

	i = 0;
	while (i < bmp->image_header.height && size)
	{
		j = 0;
		while (j < bmp->image_header.width && size)
		{
			it = &(bmp->data_palette[j + (i * bmp->image_header.width)]);
			printf("%u, %u: [%u] ", j, i, it->data);
			j++;
			size--;
		}
		printf("\n");
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_bmp	*img;

	if (argc == 2)
	{
		printf("test\n");
		img = bmp_read(argv[1]);
		if (img == NULL)
		{
			perror(__func__);
			return (-1);
		}
		printf("image_info.type\t\t\t%c%c\n", img->image_info.type >> 8, img->image_info.type & 255);
		printf("image_info.file_size\t\t%u\n", img->image_info.file_size);
		printf("image_info.offset\t\t%u\n", img->image_info.offset);
		printf("\nimage_header.size\t\t%u\n", img->image_header.size);
		printf("image_header.width\t\t%u\n", img->image_header.width);
		printf("image_header.height\t\t%u\n", img->image_header.height);
		printf("image_header.planes\t\t%u\n", img->image_header.planes);
		printf("image_header.bit_count\t\t%u\n", img->image_header.bit_count);
		printf("image_header.compression\t%u\n", img->image_header.compression);
		printf("image_header.size_image\t\t%u\n", img->image_header.size_image);
		printf("image_header.x_pixel_meter\t%u\n", img->image_header.x_pixel_meter);
		printf("image_header.y_pixel_meter\t%u\n", img->image_header.y_pixel_meter);
		printf("image_header.color_used\t\t%u\n", img->image_header.color_used);
		printf("image_header.color_important\t%u\n", img->image_header.color_important);
		if (img->palette != NULL)
			print_palette(img);
		// if (img->data_rgb != NULL)
		// 	print_data_rgb(img, 16384);
		// if (img->data_palette != NULL)
		// 	print_data_palette(img, 4489);
		bmp_delete(img);
	}
	return (0);
}
