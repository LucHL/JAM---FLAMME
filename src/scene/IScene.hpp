/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** IScene
*/

#pragma once
#include "../main.hpp"

enum sceneType {
    MAINMENU
};

class IScene {
    public:
        virtual ~IScene() = default;

        virtual void update(sf::Event &e) = 0;
        virtual void draw() = 0;
        virtual void initialize() = 0;
        virtual sceneType &getType() = 0;

    protected:
        virtual void createText(std::string text, int size, sf::Color color, sf::Vector2f pos) = 0;
        virtual void createRect(sf::Color color, sf::Color border_color, float border_size,
            sf::Vector2f origin_pos, sf::Vector2f pos, float rotation_angle, sf::Vector2f size) = 0;
        virtual void createCircle(int ray, sf::Color color, sf::Vector2f position) = 0;
        virtual void createSprite(sf::Vector2f pos, std::string sprite_image, sf::Vector2f size) = 0;

        // virtual void displayText() = 0;
        // virtual void displayRect() = 0;
        // virtual void displayCircle() = 0;
        // virtual void displaySprite() = 0;
};
