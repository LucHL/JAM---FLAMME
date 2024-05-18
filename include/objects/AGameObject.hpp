/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** AGameObject
*/

#ifndef AGAMEOBJECT_HPP_
    #define AGAMEOBJECT_HPP_
    #include "IGameObject.hpp"

class AGameObject : public IGameObject {
    public:
        AGameObject(sf::RenderWindow &win, sf::Event &event);
        ~AGameObject();

        void createWindow();
        void displayText(std::string text, int size, sf::Color color, sf::Vector2f pos);
        void displayRect();
        void displayCircle();
        void displaySprite();
        void playMusic();
        void handleEvent();

        sf::RenderWindow &getWindow() { return _window; }
        sf::Event &getEvent() { return _event; }

    private:
        sf::RenderWindow &_window;
        sf::Event &_event;
};

#endif /* !AGAMEOBJECT_HPP_ */
