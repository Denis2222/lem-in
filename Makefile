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

all: $(NAME) test demo

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
	time ./lem-in -v < ./map/10-10.map
	time ./lem-in -v < ./map/100-10.map
	time ./lem-in -v < ./map/100-15.map
	time ./lem-in -v < ./map/1000_1000.map
	time ./lem-in -v < ./map/test1
	time ./lem-in -v < ./map/20-20.map
	#time ./lem-in-v  < ./map/2000_2000.map
	time ./lem-in -v < ./map/test2
	time ./lem-in -v < ./map/300-15.map
	time ./lem-in -v < ./map/test3
	time ./lem-in -v < ./map/40-40.map
	#time ./lem-in -v < ./map/test4
	time ./lem-in -v < ./map/5-5.map
	time ./lem-in -v < ./map/test5
	time ./lem-in -v < ./map/special.map
	time ./lem-in -v < ./map/empty.map
	time ./lem-in -v < ./map/gen.map
	time ./lem-in -v < ./map/gen2.map
	time ./lem-in -v < ./map/short.map
	time ./lem-in -v < ./map/subject.map
	time ./lem-in -v < ./map/subject2.map
	time ./lem-in -v < ./map/subject3.map
	time ./lem-in -v < ./map/subject4.map
	time ./lem-in -v < ./map/noway.map
	time ./lem-in -v < ./map/test
	time ./lem-in -v < ./map/error.map
	time ./lem-in -v < ./map/lol.map

demo:
	sh ./demo.sh
