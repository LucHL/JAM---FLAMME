/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** Settings
*/

#include "Settings.hpp"

Settings::Settings(std::string backgroundPath, sf::RenderWindow &win, sceneType t)
    : AScene(backgroundPath, win, t) {
    _button.push_back(std::make_unique<MoreVolumeBtn>(sf::Vector2f(600,700)));
    _button.push_back(std::make_unique<LessVolumeBtn>(sf::Vector2f(1000, 700)));
    _button.push_back(std::make_unique<MainMenuBtn>(sf::Vector2f(800,900)));

    _settings.loadFromFile("assets/button/new_settings.png");
    _settings_s.setTexture(_settings);
    _settingsHitBox =  _settings_s.getLocalBounds();
    _settings_s.setOrigin(_settingsHitBox.width / 2, _settingsHitBox.height / 2);
    _settings_s.setPosition({(float)_window.getSize().x / 2, 300});

    _volume.loadFromFile("assets/button/volume.png");
    _volume_s.setTexture(_volume);
    _volumeHitBox =  _volume_s.getLocalBounds();
    _volume_s.setOrigin(_volumeHitBox.width / 2, _volumeHitBox.height / 2);
    _volume_s.setPosition({(float)_window.getSize().x / 2, 500});
    }

Settings::~Settings() {}

void Settings::draw() {

    _bgSprite.setTexture(_bgTexture);
    _window.draw(_bgSprite);
    for (auto &i : _button)
        i->draw(_window);
    _window.draw(_settings_s);
    _window.draw(_volume_s);
}

void Settings::update(sf::Event &e)
{
    for (auto &i : _button)
        i->update(e, _window);
}
