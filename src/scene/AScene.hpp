/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** AScene
*/

#pragma once
#include "../objects/buttons/Btn.hpp"

class AScene : public IScene {
    public:
        AScene(std::string backgroundPath, sf::RenderWindow &win, sceneType t);
        ~AScene();

        void draw();
        void update(sf::Event &e);
        void initialize();
        sceneType &getType();

    protected:
        sceneType _t;
        sf::RenderWindow &_window;
        sf::Font _font;

        sf::Texture _texture;
        sf::Sprite _sprite;
        Btn _button;
};
