/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** SceneManager
*/

#pragma once
#include "IScene.hpp"

class SceneManager {
    public:
        SceneManager(SceneManager &) = delete;
        SceneManager &operator=(const SceneManager &) = delete;

        static SceneManager &getInstance();
        bool isChange() const;
        sceneType whatchange() const;
        void setChange(bool);
        void changeScene(sceneType);
    private:
        SceneManager();
        bool _change;
        sceneType _newScene;
};
