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

        void scene();
        void update(sf::Event &e) override;
        void initialize() override;

    protected:
    private:
};

#endif /* !SETTINGS_HPP_ */
