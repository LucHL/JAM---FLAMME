/*
** EPITECH PROJECT, 2024
** Global-Game-Jam---2024---Make-Me-Laugh
** File description:
** IGameObject
*/

#ifndef IGAMEOBJECT_HPP_
    #define IGAMEOBJECT_HPP_
    #include <iostream>
    #include <map>
    #include <SFML/Graphics.hpp>

class Game;

class IGameObject {
    public:
        virtual ~IGameObject() = default;
        virtual void eventChild(const sf::Event &event, sf::RenderWindow &window, Game *game) = 0;

    protected:
    private:
};

#endif /* !IGAMEOBJECT_HPP_ */
