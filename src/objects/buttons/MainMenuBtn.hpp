/*
** EPITECH PROJECT, 2023
** JAM---FLAMME
** File description:
** MainMenu.hpp
*/

#include "ABtn.hpp"
#include "../../scene/SceneManager.hpp"

class MainMenuBtn : public ABtn {
    public:
        MainMenuBtn(sf::Vector2f pos);
        ~MainMenuBtn();

        void update(sf::Event &e, sf::RenderWindow &w);
};