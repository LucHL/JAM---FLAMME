/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** main
*/

#include "../include/objects/AGameObject.hpp"

int main() {
    sf::RenderWindow win;
    sf::Event event;
    AGameObject game(win, event);

    while (game.getWindow().isOpen()) {
        game.getWindow().clear();

        game.displayCircle(50, sf::Color::Red, sf::Vector2f(150, 5));
        game.displayCircle(50, sf::Color::Green, sf::Vector2f(10, 100));

        game.handleEvent();
        game.getWindow().display();
    }
}
