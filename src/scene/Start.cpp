/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** Start
*/

#include "Start.hpp"

Start::Start(std::string backgroundPath) {
    _backgroundText.loadFromFile(backgroundPath);
    _backgroundSprite.setTexture(_backgroundText);
    _t = sceneType::MAINMENU;
}

Start::~Start() {}

void Start::update(sf::Event &e) {
    return;
}

void Start::draw(sf::RenderWindow &w) {
    w.draw(_backgroundSprite);
}

void Start::initialize() {
    return;
}

sceneType &Start::getType() {
    return _t;
}