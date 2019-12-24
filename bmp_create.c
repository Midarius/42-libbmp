t_bmp	*bmp_create(unsigned int width, unsigned int height, unsigned int mode)
{
	t_bmp	*bmp;

	if (!(bmp = (t_bmp*)malloc(sizeof(t_bmp))))
		return (NULL);
	bmp_init_header(bmp);
	bmp_init_bip(bmp);
}
