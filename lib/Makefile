NAME = libft.a
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
HEADER  = libft.h
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = @ar rcs
RM = @rm -f

all	: $(NAME)

%.o : %.c $(HEADER)
	@($(CC) $(CFLAGS) -c $< -o $@)

$(NAME)	: $(OBJ)
	$(AR) $(NAME) $(OBJ)

fclean		: clean 
	$(RM) $(NAME)
	
clean : 
	$(RM) $(OBJ)

re: fclean all
	
.PHONY : all, clean, fclean, re,
