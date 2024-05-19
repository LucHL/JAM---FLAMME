/*
** EPITECH PROJECT, 2023
** JAM---FLAMME
** File description:
** MoreVolume.cpp
*/

#include "ABtn.hpp"
#include "../../scene/SceneManager.hpp"

class MoreVolumeBtn : public ABtn {
    public:
        MoreVolumeBtn(sf::Vector2f pos);
        ~MoreVolumeBtn();

        void update(sf::Event &e, sf::RenderWindow &w);
};