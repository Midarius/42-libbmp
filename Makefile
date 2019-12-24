CC = gcc

CFLAGS = -Wall -Wextra -O -I.

NAME = libbmp.a

SRC =	bmp_read_data_palette.c \
		bmp_read_data_rgb.c \
		bmp_read_header.c \
		bmp_read_info.c \
		bmp_read_palette.c \
		bmp_read.c \
		ft_read_skip.c \
		bmp_read_unused.c \
		bmp_delete.c \
		ft_readequ.c \
		bmp_read_data.c
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean fclean re

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
