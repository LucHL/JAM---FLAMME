##
## EPITECH PROJECT, 2024
## JAM---FLAMME
## File description:
## Makefile
##

SRC	=	src/main.cpp \
		src/Game.cpp \
		src/scene/AScene.cpp \
		src/scene/Settings.cpp	\
		src/objects/Car.cpp \
		src/objects/Road.cpp \
		src/objects/Player.cpp	\
		src/scene/MainMenu.cpp	\
		src/scene/GameScene.cpp

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
