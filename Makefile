SRCS	=	src/client.c	\
			src/server.c	\
			src/utils.c		\

PRINTF_SRCS = ft_printf/ft_printf.c		\
			ft_printf/ft_putchar.c		\
			ft_printf/ft_puthex.c		\
			ft_printf/ft_putnbr.c		\
			ft_printf/ft_putptr.c		\
			ft_printf/ft_putstr.c		\

NAMEC = client
NAMES = server
PRINTF = libftprintf.a
OBJS = $(SRCS:.c=.o)
PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)
LIBC = ar rcs
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAMEC) $(NAMES)

$(PRINTF): $(PRINTF_OBJS)
		$(LIBC) $(PRINTF) $(PRINTF_OBJS)

$(NAMEC) : src/client.o src/utils.o $(PRINTF)
		$(CC) $(CFLAGS) $^ -o $@

$(NAMES) : src/server.o $(PRINTF)
		$(CC) $(CFLAGS) $^ -o $@


clean:
		$(RM) $(OBJS) $(PRINTF_OBJS)

fclean: clean
		$(RM) $(NAMEC) $(NAMES) $(PRINTF)

re: fclean all

.PHONY : all clean fclean re