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
    Pixel(){};
    void initializePixels(std::vector<Pixel>& pixels) {
        for (auto& p : pixels) {
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

    void simulateFlame(std::vector<Pixel>& pixels, sf::Vector2f source) {
        for (auto& p : pixels) {
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
    ~Pixel(){};



private:
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Color color;
    bool active;
    sf::Clock lifespan;
};
