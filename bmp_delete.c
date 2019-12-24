#include <libbmp.h>

void	bmp_delete(t_bmp *bmp)
{
	if (bmp->image_header.unused)
		free(bmp->image_header.unused);
	if (bmp->palette)
		free(bmp->palette);
	if (bmp->data_palette)
		free(bmp->data_palette);
	if (bmp->data_rgb)
		free(bmp->data_rgb);
	free(bmp);
}
