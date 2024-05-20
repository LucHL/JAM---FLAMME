/*
** EPITECH PROJECT, 2023
** JAM---FlAMME
** File description:
** Pixel.hpp
*/

#pragma once
#include "../scene/IScene.hpp"

class Pixel {
    public:
        Pixel();
        ~Pixel();

        void initializePixels();
        void simulateFlame(sf::Vector2f source);
        void displayPixel(sf::RenderWindow &win);

    private:
        sf::Vector2f position;
        sf::Vector2f velocity;
        sf::Color color;
        bool active;
        sf::Clock lifespan;
        std::vector<std::unique_ptr<Pixel>> _pixels;
};
