/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** main
*/

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int NUM_PARTICLES = 50000;

struct Particle {
    sf::CircleShape shape;
    sf::Vector2f velocity;
    float lifespan;
};

void resetParticle(Particle& particle) {
    particle.shape.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT);
    float angle = (std::rand() % 360) * 3.14f / 180.0f;
    float speed = (std::rand() % 50) / 10.0f;
    particle.velocity = sf::Vector2f(std::cos(angle) * speed, -std::sin(angle) * speed);
    particle.lifespan = (std::rand() % 100) / 10.0f + 1.0f;
}

int main() {
    std::srand(std::time(nullptr));

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Flame Simulation");
    window.setFramerateLimit(60);

    std::vector<Particle> particles(NUM_PARTICLES);
    for (auto& particle : particles) {
        particle.shape.setRadius(2);
        particle.shape.setFillColor(sf::Color::Yellow);
        resetParticle(particle);
    }

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        float deltaTime = clock.restart().asSeconds();

        for (auto& particle : particles) {
            particle.lifespan -= deltaTime;
            if (particle.lifespan <= 0) {
                resetParticle(particle);
            } else {
                particle.velocity.y += 0.0f * deltaTime; // gravity effect
                particle.shape.move(particle.velocity);

                sf::Color color = particle.shape.getFillColor();
                color.a = static_cast<sf::Uint8>(255 * (particle.lifespan / 10.0f));
                particle.shape.setFillColor(color);
            }
        }

        window.clear(sf::Color::Black);
        for (const auto& particle : particles) {
            window.draw(particle.shape);
        }
        window.display();
    }

    return 0;
}
