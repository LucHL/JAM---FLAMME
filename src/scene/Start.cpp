/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** Start
*/

#include "Start.hpp"

Start::Start(std::string backgroundPath, std::string musicPath) {
    _backgroundText.loadFromFile(backgroundPath);
    _backgroundSprite.setTexture(_backgroundText);
    std::cerr << "heeeeyyyyy" << std::endl;
}

Start::~Start() {}

void Start::event() {
    return;
}

void Start::update() {
    return;
}

void Start::draw() {
    return;
}
