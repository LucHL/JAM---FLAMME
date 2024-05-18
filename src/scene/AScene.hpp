/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** AScene
*/

#pragma once
#include "IScene.hpp"

class AScene : public IScene {
    public:
        AScene(std::string backgroundPath, sf::RenderWindow &win, sceneType t);
        ~AScene();

        void update(sf::Event &e);
        void draw();
        void initialize();
        sceneType &getType();

        void displayText(std::string text, int size, sf::Color color, sf::Vector2f pos);
        void displayRect(sf::Color color, sf::Color border_color, float border_size,
            sf::Vector2f origin_pos, sf::Vector2f pos, float rotation_angle, sf::Vector2f size);
        void displayCircle(int ray, sf::Color color, sf::Vector2f position);
        void displaySprite(sf::Vector2f pos, std::string sprite_image, sf::Vector2f size);

    private:
        sf::Texture _backgroundText;
        sf::Sprite _backgroundSprite;
        sceneType _t;
        sf::RenderWindow &_window;
};
