CC = gcc

NAME = libftprintf.a

SRC = ft_print_d.c\
	ft_print_x.c\
	ft_printf.c\
	ft_printfchar.c\
	ft_printfp.c\
	ft_printfu.c\
	ft_printstring.c

FLAGS = -Wall -Wextra -Werror

OBJ_S = $(SRC:.c=.o)

all: $(NAME) status

$(NAME): $(OBJ_S)
	ar -rcs $@ $^ 
%.o:%.c
	@$(CC) -c $(FLAGS) -I. $< -o $@
status:
	echo "\033[5;1;92mcompleted\033[0m"
clean: status
	/bin/rm -f $(OBJ_S)

fclean:	clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
.SILENT:
