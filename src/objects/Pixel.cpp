/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** Pixel
*/

#include "Pixel.hpp"

Pixel::Pixel()
{
}

Pixel::~Pixel()
{
}

void Pixel::initializePixels()
{
    for (int i = 0; i < 800; i++)
        _pixels.push_back(std::make_unique<Pixel>());
    for (auto &p : _pixels) {
        switch (rand() % 3) {
            case 0:
                p->color = sf::Color(255, 0, 0, 100);
                break;
            case 1:
                p->color = sf::Color(255, 165, 0, 100);
                break;
            case 2:
                p->color = sf::Color(255, 255, 0, 100);
                break;
        }
        p->active = false; // Démarre inactif
    }
}

void Pixel::simulateFlame(sf::Vector2f source)
{
    for (auto &p : _pixels) {
        if (!p->active) {
            float angle = float(rand() % 45 + 45) * 3.14159f / 180.0f;
            float speed = float(rand() % 1 + 1);
            p->position = sf::Vector2f(source.x, source.y - 55);
            p->velocity = {speed * std::cos(angle), -speed * std::sin(angle)};
            p->active = true;
            p->lifespan.restart();
        }

        float randomDepop = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        if (p->active && (p->lifespan.getElapsedTime().asSeconds() < 2 && randomDepop > 0.05)) {
            p->position += p->velocity;
            p->velocity.y += 0.002;
        } else {
            p->active = false;
        }
    }
}

void Pixel::displayPixel(sf::RenderWindow &win)
{
    for (auto &p : _pixels) {
        if (p->active) {
            sf::RectangleShape pixelShape(sf::Vector2f(4, 4));
            pixelShape.setPosition(p->position);
            pixelShape.setFillColor(p->color);
            win.draw(pixelShape);
        }
    }
}
