/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** Game
*/

#include "Game.hpp"
#include "scene/AScene.hpp"
#include "scene/Settings.hpp"

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
    // _s = std::make_shared<AScene>(AScene("assets/startmenu.png", _window, sceneType::MAINMENU));
    _s = std::make_shared<Settings>(Settings("assets/startmenu.png", _window, sceneType::SETTINGS));
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

    _s->initialize();

    while (_window.isOpen()) {
        _window.clear(sf::Color::Black);

        handleEvent();
        _window.draw(_player.getSprite());
        _window.display();
    }
}

void Game::handleEvent()
{
    if (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            _window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            _player.setPosition((sf::Vector2f){-20, 0});
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            _player.setPosition((sf::Vector2f){20, 0});
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            std::cout << "Flèche de haut" << std::endl;
    }
    _s->update(_event);
    _s->draw();
}
