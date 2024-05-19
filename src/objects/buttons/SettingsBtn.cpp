/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** SettingsBtn
*/

#include "SettingsBtn.hpp"
#include "../../scene/SceneManager.hpp"

SettingsBtn::SettingsBtn(sf::Vector2f pos): ABtn("assets/button/new_settings.png", pos) {}

SettingsBtn::~SettingsBtn()
{
}

void SettingsBtn::update(sf::Event &e, sf::RenderWindow &w) {
    sf::Vector2i mp = sf::Mouse::getPosition(w);
    sf::Color base = _sprite.getColor();
    sf::Color over(base.r - 10, base.g - 10, base.b - 10);
    if (isMouseOver(w)) {
        _sprite.setColor(over);
        if (e.type == sf::Event::MouseButtonPressed) {
            SceneManager &inst = SceneManager::getInstance();
            inst.setChange(true);
            inst.changeScene(sceneType::SETTINGS);
        }
    } else
        _sprite.setColor(base);
}
