/*
** EPITECH PROJECT, 2023
** JAM---FlAMME
** File description:
** Pixel.hpp
*/

#pragma once
#include "../scene/IScene.hpp"
#include <cmath>

class Pixel {
    public:
        Pixel();
        ~Pixel();

        void initializePixels(std::vector<Pixel> &pixels);
        void simulateFlame(std::vector<Pixel> &pixels, sf::Vector2f source);

    private:
        sf::Vector2f position;
        sf::Vector2f velocity;
        sf::Color color;
        bool active;
        sf::Clock lifespan;
};
