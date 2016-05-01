SRCS = main.c \
		parsing.c \
		t_room.c \
		t_room_getter.c \
		t_wire.c \
		is.c \
		resolve.c \
		t_ant.c \
		t_screen.c \
		display.c \
		draw.c \
		t_li.c \
		opts.c

NAME = lem-in
GCC_FLAGS = -Wall -Werror -Wextra
CC = gcc $(GCC_FLAGS)
SRCDIR = ./
OBJDIR = ./objs
AR = ar -cq
RM = rm -rf
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
LIBFT = ./libft/libft.a

all: $(NAME)

$(LIBFT):
	@make -C libft
	@echo $(SRC_LIB_O)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -o $(NAME) $(OBJS) -lft -L./libft/

$(addprefix $(OBJDIR)/, %.o): $(addprefix $(SRCDIR)/, %.c)
	@mkdir -p $(OBJDIR)
	@$(CC) -o $@ -c $^

clean:
	@$(RM) $(OBJDIR)

fclean: clean
	@$(RM) $(NAME)
	@make -C libft fclean

re: fclean all

test: clean $(NAME)
	./lem-in < ./map/empty.map
