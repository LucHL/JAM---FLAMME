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
        void displayText(std::string text, int size, sf::Color color, sf::Vector2f pos);
        void displayRect(sf::Color color, sf::Color border_color, float border_size,
            sf::Vector2f origin_pos, sf::Vector2f pos, float rotation_angle, sf::Vector2f size);
        void displayCircle(int ray, sf::Color color, sf::Vector2f position);
        void displaySprite(sf::Vector2f pos, std::string sprite_image, sf::Vector2f size);
        void playMusic(std::string filename);
        void handleEvent();

        void changeScenes();

        void gameLoop();
        sf::RenderWindow &getWindow() { return _window; }
        sf::Event &getEvent() { return _event; }

    private:
        sf::RenderWindow &_window;
        sf::Event &_event;
        std::unordered_map<std::size_t, std::unique_ptr<IScene>> _scenes;
};

#endif /* !GAME_HPP_ */
