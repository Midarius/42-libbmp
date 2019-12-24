#include <libbmp_util.h>

int	ft_read_skip(const int fd, unsigned int size)
{
	unsigned char c;
	int rtn;
	int total;

	total = 0;
	while (size)
	{
		if ((rtn = read(fd, &c, sizeof(unsigned char))) < 1)
			return (rtn);
		total += rtn;
		size--;
	}
	return (total);
}
