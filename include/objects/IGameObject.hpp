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
        virtual void displayRect(sf::Color color, sf::Color border_color, float border_size,
        sf::Vector2f origin_pos, sf::Vector2f pos, float rotation_angle, sf::Vector2f size) = 0;
        virtual void displayCircle(int ray, sf::Color color, sf::Vector2f position) = 0;
        virtual void displaySprite() = 0;
        virtual void playMusic(std::string filename) = 0;
        virtual void handleEvent() = 0;
};

#endif /* !IGAMEOBJECT_HPP_ */
