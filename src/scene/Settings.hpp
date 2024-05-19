/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** Settings
*/

#ifndef SETTINGS_HPP_
    #define SETTINGS_HPP_
    #include "AScene.hpp"

class Settings : public AScene {
    public:
        Settings(std::string backgroundPath, sf::RenderWindow &win, sceneType t);
        ~Settings();

        void update(sf::Event &e) override;
        void draw();
};

#endif /* !SETTINGS_HPP_ */
