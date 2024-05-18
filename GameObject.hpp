/*
** EPITECH PROJECT, 2024
** Global-Game-Jam---2024---Make-Me-Laugh
** File description:
** GameObject
*/

#ifndef GAMEOBJECT_HPP_
    #define GAMEOBJECT_HPP_
    #include "IGameObject.hpp"
class Game;

class GameObject : public IGameObject
{
    public:
        GameObject(const std::string &textureName, const sf::Vector2f position, sf::IntRect rect);
        virtual ~GameObject();

        void eventChild(const sf::Event &event, sf::RenderWindow &window, Game *game) override;
        void event(const sf::Event &event, sf::RenderWindow &window, Game *game);

        virtual void updateChild(const float deltaTime);
        void update(const float deltaTime);

        virtual void drawChild(sf::RenderWindow &window);
        void draw(sf::RenderWindow &window);

        void setAnimation();
        void setAnimation(const sf::Vector2f offset,
                          const sf::Vector2f maxOffset,
                          const sf::IntRect rect,
                          const float spriteAnimationTimeInterval);

        void setStatus(const bool hidden, const bool clickable);
        void setHidden(const bool hidden);
        void setClickable(const bool clickable);
        void setPosition(const sf::Vector2f &position);
        void setSize(const sf::Vector2f &size);
        void setTexture(const std::string &fileName, const sf::IntRect &area);
        void setTexture(const sf::Texture &texture);

        void refreshTexture();

        const sf::Sprite &getSprite() const;
        const sf::Vector2f getPosition() const;

        void setScale(sf::Vector2f scale);

    protected:
        sf::Texture _texture;
        sf::Sprite _sprite;
        sf::Vector2f _position;

        bool _isAnimated;
        sf::Vector2f _offset;
        sf::Vector2f _maxOffset;
        sf::IntRect _currentRect;
        float _spriteLastAnimatedTime;
        float _spriteAnimationTimeInterval;

        bool _isHidden;
        bool _isClickable;
        virtual void onClick();

    private:
};

#endif /* !GAMEOBJECT_HPP_ */
