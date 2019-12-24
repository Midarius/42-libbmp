#include <libbmp.h>
#include <stdio.h>

int	bmp_read_info(int fd, t_bmp *bmp)
{
	printf("%s\n", __func__);
	if (ft_readequ(fd, &(bmp->image_info.type), sizeof(unsigned short)) < 1 ||
	ft_readequ(fd, &(bmp->image_info.file_size), sizeof(unsigned int)) < 1 ||
	ft_readequ(fd, &(bmp->image_info.reserved1), sizeof(unsigned short)) < 1 ||
	ft_readequ(fd, &(bmp->image_info.reserved2), sizeof(unsigned short)) < 1 ||
	ft_readequ(fd, &(bmp->image_info.offset), sizeof(unsigned int)) < 1)
		return (-1);
	return (0);
}
