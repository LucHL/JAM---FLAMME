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

void AGameObject::displayRect(sf::Color color, sf::Color border_color, float border_size,
    sf::Vector2f origin_pos, sf::Vector2f pos, float rotation_angle, sf::Vector2f size)
{
    sf::RectangleShape rect;

    rect.setFillColor(color);
    rect.setOutlineColor(border_color);
    rect.setOutlineThickness(border_size);
    rect.setOrigin(origin_pos.x, origin_pos.y);
    rect.setPosition(pos.x, pos.y);
    rect.setRotation(rotation_angle);
    rect.setSize(size);
    _window.draw(rect);
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
