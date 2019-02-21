##
## EPITECH PROJECT, 2018
## makefile
## File description:
## compilation
##

SRC =       $(wildcard src/*.c)

OBJ =   $(SRC:.c=.o)

NAME =  my_hunter

RM = rm -f -r

CFLAGS += -I./include -lcsfml-system -lcsfml-window -lcsfml-graphics -lcsfml-audio

$(NAME):    $(OBJ)
		gcc $(OBJ) $(CFLAGS) -o $(NAME) -g
		rm -f $(OBJ)

all:    $(NAME)

clean:
	@$(RM) *~
	@$(RM) *.o
	@printf "Les fichiers ~ et .o ont été supprimé\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "Le fichier cat a été supprimé\n"

re: fclean all
