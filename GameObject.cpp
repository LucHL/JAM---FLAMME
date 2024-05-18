/*
** EPITECH PROJECT, 2024
** Global-Game-Jam---2024---Make-Me-Laugh
** File description:
** GameObject
*/

#include "../../Include/Objects/GameObject.hpp"
#include "../../Include/Game/Game.hpp"

GameObject::GameObject(const std::string &textureName, const sf::Vector2f position, sf::IntRect rect)
: _texture(sf::Texture()), _sprite(_texture)
{
    if (textureName != "") {
        _texture = sf::Texture();
        _texture.loadFromFile(textureName);
        _sprite = sf::Sprite(_texture);
        _position = position;
        _sprite.setPosition(position);
    } else {
        _texture = sf::Texture();
        _sprite = sf::Sprite();
    }

    _isAnimated = false;
    _offset = sf::Vector2f(0.0f, 0.0f);
    _maxOffset = sf::Vector2f(0.0f, 0.0f);
    _currentRect = rect;
    _sprite.setTextureRect(_currentRect);
    _spriteLastAnimatedTime = 0.0f;
    _spriteAnimationTimeInterval = 0.0f;

    _isHidden = false;
    _isClickable = false;
}

GameObject::~GameObject()
{
}

void GameObject::updateChild(const float deltaTime)
{
    (void)deltaTime;
    return;
}

void GameObject::update(const float deltaTime)
{
    updateChild(deltaTime);
    if (_isAnimated && _spriteLastAnimatedTime + _spriteAnimationTimeInterval > deltaTime)
        return;
    _spriteLastAnimatedTime = deltaTime;
    if (_currentRect.left >= _maxOffset.x) {
        if (_currentRect.top >= _maxOffset.y) {
            _currentRect.top = 0;
        } else {
            _currentRect.top += _offset.y;
        }
        _currentRect.left = 0;
    } else {
        _currentRect.left += _offset.x;
    }
    _sprite.setTextureRect(_currentRect);
    return;
}

void GameObject::eventChild(const sf::Event &event, sf::RenderWindow &window, Game *game)
{
    (void)event;
    (void)window;
    (void)game;
    return;
}

void GameObject::event(const sf::Event &event, sf::RenderWindow &window, Game *game)
{
    eventChild(event, window, game);
}

void GameObject::drawChild(sf::RenderWindow &window)
{
    (void)window;
}

void GameObject::draw(sf::RenderWindow &window)
{
    _sprite.setTexture(_texture);
    if (!_isHidden) {
        window.draw(_sprite);
    }
    this->drawChild(window);
    return;
}

void GameObject::setAnimation()
{
    _isAnimated = false;
    return;
}

void GameObject::setAnimation(const sf::Vector2f offset,
                    const sf::Vector2f maxOffset,
                    const sf::IntRect rect,
                    const float spriteAnimationTimeInterval)
{
    if (offset.x == 0 && offset.y == 0) {
        _isAnimated = false;
        return;
    }
    _isAnimated = true;
    _offset = offset;
    _maxOffset = maxOffset;
    _currentRect = rect;
    _spriteLastAnimatedTime = 0;
    _spriteAnimationTimeInterval = spriteAnimationTimeInterval;
}

void GameObject::setStatus(const bool hidden, const bool clickable)
{
    setHidden(hidden);
    setClickable(clickable);
}

void GameObject::setHidden(const bool hidden)
{
    _isHidden = hidden;
}

void GameObject::setClickable(const bool clickable)
{
    _isClickable = clickable;
}

void GameObject::onClick()
{
    return;
}

const sf::Sprite &GameObject::getSprite() const
{
    return _sprite;
}

const sf::Vector2f GameObject::getPosition() const
{
    return (_position);
}

void GameObject::setPosition(const sf::Vector2f &position) {
    _position = position;
    _sprite.setPosition(_position);
}

void GameObject::setSize(const sf::Vector2f &size) {
    _sprite.setScale(size.x / _sprite.getGlobalBounds().width,
                     size.y / _sprite.getGlobalBounds().height);
}

void GameObject::setScale(sf::Vector2f scale)
{
    _sprite.setScale(scale);
}

void GameObject::setTexture(const std::string &fileName, const sf::IntRect &area)
{
    _texture.loadFromFile(fileName, area);
}

void GameObject::setTexture(const sf::Texture &texture)
{
    _texture = texture;
}

void GameObject::refreshTexture()
{
    _sprite.setTexture(_texture);
}
