##
## EPITECH PROJECT, 2024
## JAM---FLAMME
## File description:
## Makefile
##

SRC	=	src/main.cpp \
		src/objects/AGameObject.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	flamme

CPPFLAG	=	-std=c++20 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all:	$(NAME)
$(NAME): $(OBJ)
	g++ -o $(NAME) $(SRC) $(CPPFLAG)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
