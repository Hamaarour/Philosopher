NAME= philo
CC= cc
CFLAGS= -Wall -Wextra -Werror -pthread
RM= rm -f

SRC=main.c utils.c start_philo.c\
	
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re