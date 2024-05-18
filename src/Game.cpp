/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** Game
*/

#include "Game.hpp"
#include "scene/AScene.hpp"

Game::Game(sf::RenderWindow &win, sf::Event &event) : _window(win), _event(event)
{
    createWindow();
}

Game::~Game() {}

void Game::createWindow()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    _window.create(sf::VideoMode(1920, 1080), "FLAMME", sf::Style::Default, settings);
}

void Game::playMusic(std::string filename)
{
    sf::Music music;

    if (!music.openFromFile(filename)) {
        std::cerr << "Fail to load music." << std::endl;
        return;
    }
    music.play();
}

void Game::gameLoop() {
    while (_window.isOpen()) {
        _window.clear(sf::Color::Black);

        handleEvent();

        _s->update(_event);
        _s->draw(_window);
        _window.display();
    }
}

void Game::handleEvent()
{
    if (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            _window.close();
        }
    }
}
