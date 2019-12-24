#ifndef LIBBMP_UTIL_H
# define LIBBMP_UTIL_H

#include <unistd.h>
#include <fcntl.h>

int	ft_readequ(int fd, void *buf, size_t count);
int	ft_read_skip(const int fd, unsigned int size);

#endif
