SRCS			=	ft_strlen.s\
					ft_strcpy.s\
					ft_strcmp.s\
					ft_write.s\
					ft_read.s\
					ft_strdup.s\
					ft_atoi_base.s\
					ft_list_push_front.s

SRCC			= main.c
NAME			= libasm.a

OBJS			= $(SRCS:.s=.o)
OBJC			= $(SRCC:.c=.o)

CFLAGS			= -Wall -Wextra -Werror
ASFLAGS			= -fmacho64
AR				= ar rc
CC				= gcc
AS				= nasm

$(NAME):		$(OBJS)
				$(AR) $(NAME) $(OBJS)

all:			$(NAME)

test:			$(NAME) $(OBJC)
				$(CC) -L. -lasm $(OBJC)
				./a.out

clean:
				$(RM) $(OBJS)
				$(RM) $(OBJC)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all
