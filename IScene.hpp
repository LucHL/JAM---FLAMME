/*
** EPITECH PROJECT, 2024
** Global-Game-Jam---2024---Make-Me-Laugh
** File description:
** Scene
*/

#ifndef SCENE_HPP_
    #define SCENE_HPP_
    #include <iostream>
    #include <SFML/Graphics.hpp>
    #include <SFML/Audio.hpp>

enum SceneName
{
    STARTMENU,
    SONGSELECT,
    GAMEPLAY,
    SETTINGS,
    PAUSE,
    DEFEATSCREEN,
    WINSCREEN
};

class Game;

class IScene 
{
    public:
        virtual ~IScene() = default;


        virtual SceneName getName() = 0;

        // Methods to handle input events
        virtual void handleEvent(const sf::Event& event, sf::RenderWindow &window, Game *game) = 0;

        // Method to update the scene logic
        virtual void update(float deltaTime) = 0;

        // Method to render the scene
        virtual void render(sf::RenderWindow& window) = 0;

        // Method to handle initialization of the scene
        virtual void initialize() = 0;

        // Method to handle cleanup when scene is exited
        virtual void cleanup() = 0;

        virtual void setupSprites() = 0;
};

#endif /* !SCENE_HPP_ */
