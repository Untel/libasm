SRCS			=	ft_strlen.s\
					ft_strcpy.s\
					ft_strcmp.s\
					ft_write.s\
					ft_read.s\
					ft_strdup.s

SRCSBONUS		=	ft_atoi_base_bonus.s\
					ft_list_push_front_bonus.s\
					ft_list_size_bonus.s\
					ft_list_sort_bonus.s\
					ft_list_remove_if_bonus.s

SRCC			= main.c
SRCCBONUS		= main_bonus.c

NAME			= libasm.a
NAMEBONUS		= libasmbonus.a

OBJS			= $(SRCS:.s=.o)
OBJSBONUS		= $(SRCSBONUS:.s=.o)
OBJC			= $(SRCC:.c=.o)
OBJCBONUS		= $(SRCCBONUS:.c=.o)

CFLAGS			= -Wall -Wextra -Werror
ASFLAGS			= -fmacho64
AR				= ar rc
CC				= gcc
AS				= nasm

all:			$(NAME)

$(NAMEBONUS):	$(OBJS) $(OBJSBONUS)
				$(AR) $(NAMEBONUS) $(OBJS) $(OBJSBONUS)

$(NAME):		$(OBJS)
				$(AR) $(NAME) $(OBJS)

bonus:			$(NAMEBONUS)

test:			all $(OBJC)
				$(CC) -L. -lasm $(OBJC)
				./a.out

test_bonus:		bonus $(OBJCBONUS)
				$(CC) -L. -lasmbonus $(OBJCBONUS)
				./a.out

clean:
				$(RM) $(OBJS)
				$(RM) $(OBJC)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all
