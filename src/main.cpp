/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** main
*/

#include "../include/objects/AGameObject.hpp"

int main()
{
    sf::RenderWindow win;
    sf::Event event;
    AGameObject game(win, event);

    while (game.getWindow().isOpen()) {
        game.getWindow().clear();

        game.displayText("ceci est du text", 50, sf::Color::Blue, sf::Vector2f(100, 200));

        game.handleEvent();
        game.getWindow().display();
    }
}
