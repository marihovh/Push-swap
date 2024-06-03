NAME=push_swap
CHECKER=checker
SRC=$(wildcard *.c)
SRCB = $(filter-out main.c action_1.c action_2.c, $(SRC)) $(wildcard check/*.c)  
OBJ=$(SRC:.c=.o)
OBJB=$(SRCB:.c=.o)
CC= gcc
LIBFT=lib/libft.a
PRINTF=printf/libftprintf.a
CFLAGS= -Wall -Werror -Wextra
RM = rm -rf

all : comp $(NAME)

bonus : comp $(OBJB)

	$(CC) $(CFLAGS) $(OBJB) $(PRINTF) $(LIBFT) -o $(CHECKER)

comp : 
	cd ./lib && make
	cd ./printf && make

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF) $(LIBFT) -o $(NAME)

fclean : clean
	cd ./lib && make fclean
	cd ./printf && make fclean
	$(RM) $(NAME)
	$(RM) $(CHECKER)

clean :
	cd ./lib && make clean
	cd ./printf && make clean
	$(RM) $(OBJ)
	$(RM) $(OBJB)

re : fclean all bonus

.PHONY : all, clean, flcean, re