##
## EPITECH PROJECT, 2024
## JAM---FLAMME
## File description:
## Makefile
##

SRC	=	src/main.cpp \
		src/Game.cpp \
		src/objects/Car.cpp \
		src/objects/Player.cpp \
		src/objects/Road.cpp \
		src/objects/buttons/ABtn.cpp \
		src/objects/buttons/ExitBtn.cpp \
		src/objects/buttons/SettingsBtn.cpp \
		src/objects/buttons/StartBtn.cpp \
		src/objects/Pixel.cpp \
		src/scene/AScene.cpp \
		src/scene/GameScene.cpp \
		src/scene/MainMenu.cpp \
		src/scene/SceneManager.cpp \
		src/scene/Settings.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	flamme

CPPFLAG	=	-std=c++20 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all:	$(NAME)
$(NAME): $(OBJ)
	g++ -o $(NAME) $(OBJ) $(CPPFLAG)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
