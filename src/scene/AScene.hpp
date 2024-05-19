/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** AScene
*/

#pragma once
#include "../objects/buttons/StartBtn.hpp"
#include "../objects/buttons/SettingsBtn.hpp"

class AScene : public IScene {
    public:
        AScene(std::string backgroundPath, sf::RenderWindow &win, sceneType t);
        ~AScene();

        virtual void draw() = 0;
        virtual void initialize() = 0;
        void update(sf::Event &e);

    protected:
        sceneType _t;
        sf::RenderWindow &_window;
        sf::Font _font;

        sf::Texture _texture;
        sf::Sprite _sprite;
        std::vector<std::shared_ptr<IBtn>> _button;
};
