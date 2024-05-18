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
        if (game.getWindow().pollEvent(game.getEvent())) {
            if (game.getEvent().type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                game.getWindow().close();
            }
        }
        game.getWindow().display();
    }
}
