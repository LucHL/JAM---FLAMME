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
        void displayRect(sf::Color color, sf::Color border_color, float border_size,
            sf::Vector2f origin_pos, sf::Vector2f pos, float rotation_angle, sf::Vector2f size);
        void displayCircle(int ray, sf::Color color, sf::Vector2f position);
        void displaySprite(sf::Vector2f pos, std::string sprite_image, sf::Vector2f size);
        void playMusic(std::string filename);
        void handleEvent();

        sf::RenderWindow &getWindow() { return _window; }
        sf::Event &getEvent() { return _event; }

    private:
        sf::RenderWindow &_window;
        sf::Event &_event;
        // std::unordered_map<int, Scnene> _scenes;
        // int _currentScene;
};

#endif /* !AGAMEOBJECT_HPP_ */
