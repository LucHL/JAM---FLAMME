/*
** EPITECH PROJECT, 2023
** JAM---FLAMME
** File description:
** LessVolume.hpp
*/

#include "ABtn.hpp"
#include "../../scene/SceneManager.hpp"

class LessVolumeBtn : public ABtn {
    public:
        LessVolumeBtn(sf::Vector2f pos);
        ~LessVolumeBtn();

        void update(sf::Event &e, sf::RenderWindow &w);
};