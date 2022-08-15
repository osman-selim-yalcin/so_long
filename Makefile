SRCS = check.c playermove.c put.c readmap.c so_long.c gnl/get_next_line.c gnl/get_next_line_utils.c walkwrite.c

OBJS = $(SRCS:.c=.o)

EXT = printf/libftprintf.a minilibx/libmlx.a

CC = gcc

FLAGS =  -Wall -Wextra -Werror

RM = rm -rf

NAME = so_long

all :$(EXT) $(NAME)

$(EXT):
	make -C printf
	make -C minilibx

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(EXT) $(FLAGS) -framework OpenGL -framework AppKit -o $(NAME)

fclean : clean
	$(RM) *.a
	$(RM) printf/*.a
	$(RM) gnl/*.a
	$(RM) $(NAME)

clean :
	$(RM) *.o
	$(RM) printf/*.o
	$(RM) gnl/*.o


re : fclean all

.PHONY : all bonus fclean clean re