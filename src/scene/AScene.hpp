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

        void draw();
        void update(sf::Event &e);
        void initialize();
        sceneType &getType();

        void createText(std::string text, int size, sf::Color color, sf::Vector2f pos);
        void createRect(sf::Color color, sf::Color border_color, float border_size,
            sf::Vector2f origin_pos, sf::Vector2f pos, float rotation_angle, sf::Vector2f size, bool NeedCenter);
        void createCircle(int ray, sf::Color color, sf::Vector2f position);
        void createSprite(sf::Vector2f pos, std::string sprite_image, sf::Vector2f size, bool NeedCenter);

    protected:
        sceneType _t;
        sf::RenderWindow &_window;
        sf::Font _font;
        sf::Texture _texture;

        std::vector<sf::Text> _text;
        std::vector<sf::RectangleShape> _rect;
        std::vector<sf::CircleShape> _circle;
        std::vector<sf::Sprite> _sprite;
};
