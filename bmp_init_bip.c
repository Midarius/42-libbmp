int	bmp_init_bip(t_bmp *bmp)
{
	bmp->image_header.size = 40;
	bmp->image_header.width = width;
	bmp->image_header.height = height;
	bmp->image_header.planes = 1;
	bmp->image_header.bit_count = mode;
	bmp->image_header.compression = 0;
	bmp->image_header.size_image = 0;
	bmp->image_header.x_pixel_meter = 0;
	bmp->image_header.y_pixel_meter = 0;
	bmp->image_header.color_used = 0;
	bmp->image_header.color_important = 0;
	bmp->image_header.unused = NULL;
}
