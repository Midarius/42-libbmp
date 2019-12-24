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
