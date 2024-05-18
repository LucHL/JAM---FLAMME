/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** AGameObject
*/

#include "../../include/objects/AGameObject.hpp"

AGameObject::AGameObject(sf::RenderWindow &win, sf::Event &event) : _window(win), _event(event)
{
    createWindow();
}

AGameObject::~AGameObject() {}

void AGameObject::createWindow()
{
    _window.create(sf::VideoMode(1920, 1080), "FLAMME");
}

void AGameObject::displayText(std::string text, int size, sf::Color color, sf::Vector2f pos)
{
    sf::Font font;
    sf::Text to_draw;

    if (!font.loadFromFile("src/objects/Arial.ttf"))
        return;
    to_draw.setFont(font);
    to_draw.setString(text);
    to_draw.setCharacterSize(size);
    to_draw.setFillColor(color);
    to_draw.setPosition(pos.x, pos.y);
    _window.draw(to_draw);
}

void AGameObject::displayRect()
{

}

void AGameObject::displayCircle()
{

}

void AGameObject::displaySprite()
{

}

void AGameObject::playMusic()
{

}

void AGameObject::handleEvent()
{

}
