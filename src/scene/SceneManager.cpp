/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** SceneManager
*/

#include "SceneManager.hpp"

SceneManager &SceneManager::getInstance() {
    static SceneManager instance;
    return instance;
}

SceneManager::SceneManager() : _change(false), _newScene(sceneType::MAINMENU) {}

bool SceneManager::isChange() const {
    return _change;
}

sceneType SceneManager::whatchange() const {
    return _newScene;
}

void SceneManager::setChange(bool c) {
    _change = c;
}

void SceneManager::changeScene(sceneType t) {
    _newScene = t;
}
