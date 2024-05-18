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

void AGameObject::displayText()
{

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
