/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** IGameObject
*/

#ifndef IGAMEOBJECT_HPP_
    #define IGAMEOBJECT_HPP_
    #include "../main.hpp"

class IGameObject {
    public:
        virtual ~IGameObject() = default;

        virtual void createWindow() = 0;
        virtual void displayText(std::string text, int size, sf::Color color, sf::Vector2f pos) = 0;
        virtual void displayRect() = 0;
        virtual void displayCircle() = 0;
        virtual void displaySprite() = 0;
        virtual void playMusic() = 0;
        virtual void handleEvent() = 0;
};

#endif /* !IGAMEOBJECT_HPP_ */
