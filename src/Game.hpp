/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** Game
*/

#ifndef GAME_HPP_
    #define GAME_HPP_
    #include "main.hpp"
    #include "scene/IScene.hpp"

class Game {
    public:
        Game(sf::RenderWindow &win, sf::Event &event);
        ~Game();

        void createWindow();
        void handleEvent();
        void gameLoop();
        void playMusic(std::string filename);
        void changeScene(sceneType);

    private:
        sf::RenderWindow &_window;
        sf::Event &_event;
        std::unique_ptr<IScene> _s;
};

#endif /* !GAME_HPP_ */
