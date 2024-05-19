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

void Pixel::initializePixels(std::vector<Pixel> &pixels)
{
    for (auto &p : pixels) {
        switch (rand() % 3) {
            case 0:
                p.color = sf::Color(255, 0, 0, 100);  // Rouge avec transparence
                break;
            case 1:
                p.color = sf::Color(255, 165, 0, 100);  // Orange avec transparence
                break;
            case 2:
                p.color = sf::Color(255, 255, 0, 100);  // Jaune avec transparence
                break;
        }
        p.active = false; // Démarre inactif
    }
}

void Pixel::simulateFlame(std::vector<Pixel> &pixels, sf::Vector2f source)
{
    for (auto &p : pixels) {
        if (!p.active) {
            float angle = float(rand() % 45 + 45) * 3.14159f / 180.0f;
            float speed = float(rand() % 1 + 1);
            p.position = source;
            p.velocity = {speed * std::cos(angle), -speed * std::sin(angle)};
            p.active = true;
            p.lifespan.restart();
        }

        float randomDepop = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        if (p.active && (p.lifespan.getElapsedTime().asSeconds() < 2 && randomDepop > 0.05)) {
            p.position += p.velocity;
            p.velocity.y += 0.002;
        } else {
            p.active = false;
        }
    }
}

void Pixel::displayPixel(std::vector<Pixel> &pixels, sf::RenderWindow &win)
{
    for (auto &pixel : pixels) {
        if (pixel.active) {
            sf::RectangleShape pixelShape(sf::Vector2f(4, 4)); // Assurez-vous que la taille est correcte
            pixelShape.setPosition(pixel.position);
            pixelShape.setFillColor(pixel.color);
            win.draw(pixelShape);
        }
    }
}
