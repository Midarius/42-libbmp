#include <limits.h>

#include <libbmp_util.h>

int	ft_readequ(int fd, void *buf, size_t count)
{
	int rtn;

	if (count > INT_MAX)
		return (-1);
	if ((rtn = read(fd, buf, count)) != (int)count)
		return (-1);
	return (rtn);
}
