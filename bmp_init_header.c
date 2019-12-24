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
