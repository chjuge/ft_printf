DIR1	=	./src/print_by_type
DIR2	=	./src/utils

SRCS	=	./src/ft_printf.c \
			$(DIR1)/print_by_type.c \
			$(DIR1)/print_c.c \
			$(DIR1)/print_s.c \
			$(DIR1)/print_d.c \
			$(DIR1)/print_u.c \
			$(DIR1)/print_x.c \
			$(DIR1)/print_p.c \
			$(DIR2)/adjust_by_sharp.c \
			$(DIR2)/chech_for_flags.c \
			$(DIR2)/copy_from_back.c \
			$(DIR2)/defines.c \
			$(DIR2)/fill_struct.c \
			$(DIR2)/ft_atoi.c \
			$(DIR2)/ft_isdigit.c \
			$(DIR2)/ft_itoa.c \
			$(DIR2)/ft_putstr.c \
			$(DIR2)/ft_strdup.c \
			$(DIR2)/ft_strncmp.c \
			$(DIR2)/ft_strlen.c \
			$(DIR2)/to_hex.c \
			$(DIR2)/write_while.c \
			$(DIR2)/adjasting.c \
			$(DIR2)/print_on_screen.c

OBJS	= 	$(SRCS:.c=.o)

HEAD	=	./src/headers/ft_printf.h

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -rf

NAME	=	libftprintf.a

all:		$(NAME)

$(NAME):	$(OBJS) $(HEAD)
			ar rcs $(NAME) $(OBJS)

clean:		
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

bonus:		all

.PHONY:		all clean fclean re bonus