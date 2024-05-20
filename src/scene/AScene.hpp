/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** AScene
*/

#pragma once
#include "../objects/buttons/StartBtn.hpp"
#include "../objects/buttons/SettingsBtn.hpp"
#include "../objects/buttons/ExitBtn.hpp"
#include "../objects/buttons/MainMenuBtn.hpp"
#include "../objects/buttons/MoreVolume.hpp"
#include "../objects/buttons/LessVolume.hpp"
#include "../objects/Pixel.hpp"

class AScene : public IScene {
    public:
        AScene(std::string backgroundPath, sf::RenderWindow &win, sceneType t);
        ~AScene();

        virtual void draw() = 0;
        void update(sf::Event &e);

    protected:
        sceneType _t;
        sf::RenderWindow &_window;
        sf::Font _font;

        sf::Texture _bgTexture;
        sf::Sprite _bgSprite;
        std::vector<std::unique_ptr<IBtn>> _button;
        std::unique_ptr<sf::Music> _music;
        Pixel _p;
        std::vector<std::unique_ptr<Pixel>> _pixels;
};
