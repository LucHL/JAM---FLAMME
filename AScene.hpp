/*
** EPITECH PROJECT, 2024
** Global-Game-Jam---2024---Make-Me-Laugh
** File description:
** AScene
*/

#ifndef ASCENE_HPP_
    #define ASCENE_HPP_
    #include "IScene.hpp"
    #include "../Objects/GameObject.hpp"
    #include <vector>

class AScene : public IScene
{
    public:

        AScene(const SceneName sceneName, const std::string &backgroundName);
        ~AScene() override;

        AScene(const AScene& other);

        virtual SceneName getName() override;
        // Methods to handle input events
        virtual void handleEvent(const sf::Event &event, sf::RenderWindow &window, Game *game) override;

        // Method to update the scene logic
        virtual void update(float deltaTime) override;

        // Method to render the scene
        void render(sf::RenderWindow &window) override;

        // Method to handle initialization of the scene
        virtual void initialize() override;

        // Method to handle cleanup when scene is exited
        virtual void cleanup() override;

        virtual void setupSprites() override;

    protected:
        SceneName _sceneName;
        sf::Texture _textureBackground;
        sf::Sprite _spriteBackground;
        sf::Font _font;
        std::map<std::string, sf::Sound> _soundsMap;
        std::vector<GameObject*> _gameObjects;
        sf::Music _ambiantMusic;
        void setBackground(const std::string &backgroundName);
    private:
};

#endif /* !ASCENE_HPP_ */
