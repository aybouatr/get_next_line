NAME	:= get_next_line.a

SRC := get_next_line.c get_next_line_utils.c get_next_line.h

CC := cc
AR := ar rcs

FLAGS := -Wall -Wextra -Werror

OBJS := $(SRC:.c=.o)


all : $(NAME)

$(NAME) = $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
