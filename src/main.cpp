/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** main
*/

#include "Game.hpp"

int main()
{
    sf::RenderWindow win;
    sf::Event event;
    Game game(win, event);

    game.gameLoop();
}
