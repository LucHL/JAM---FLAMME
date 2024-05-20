/*
** EPITECH PROJECT, 2023
** JAM---FLAMME
** File description:
** Player.cpp
*/

#include "Player.hpp"
#include "Road.hpp"

Player::Player()
{
    _rect.top = 64;
    _rect.left = 192;
    _rect.width = 32;
    _rect.height = 64;
    _texture.loadFromFile("assets/characters/char_chef.png", _rect);
    _sprite.setTexture(_texture, true);
    _pos.x = 944;
    _pos.y = 920;
    _sprite.setPosition(_pos);
    _state = 0;
}

Player::~Player()
{
}

bool Player::checkPlayerCollision(const sf::Sprite &collision, sf::Vector2f newPos) {
    sf::Image image2 = collision.getTexture()->copyToImage();
    sf::FloatRect sprite1Bounds = _sprite.getGlobalBounds();
    int posX;
    int posY;

    sprite1Bounds.left = (newPos.x < 0) ? sprite1Bounds.left + newPos.x + 10: sprite1Bounds.left + newPos.x - 10;
    sprite1Bounds.top += (newPos.y + 15);
    for (int x = sprite1Bounds.left; x < sprite1Bounds.left + sprite1Bounds.width; ++x)
        for (int y = sprite1Bounds.top; y < sprite1Bounds.top + sprite1Bounds.height; ++y) {
            posX = x - collision.getPosition().x;
            posY = y - collision.getPosition().y;
            if (posX >= 0 && posX < image2.getSize().x && posY >= 0 && posY < image2.getSize().y) {
                sf::Color pixelColor = image2.getPixel(posX, posY);
                if (pixelColor != sf::Color::Transparent)
                    return true;
            }
        }
    return false;
}

void Player::changePlayerPos(sf::Vector2f pos)
{
    _pos.x += pos.x;
    if (_pos.x < 0)
        _pos.x = 0;
    if (_pos.x > 1888)
        _pos.x = 1888;
    _pos.y += pos.y;
    _sprite.setPosition(_pos);
}

void Player::changePlayerSkin(int top, int left)
{
    _rect.top = top;
    _rect.left = left;
    _texture.loadFromFile("assets/characters/char_chef.png", _rect);
    _sprite.setTexture(_texture, true);
}

void Player::movePlayerUp(std::vector<std::shared_ptr<Road>> road, int *builderPos) {
    if (_state == 0)
        changePlayerSkin(64, 192);
    if (_state == 1)
        changePlayerSkin(128, 224);
    if (_state == 2)
        changePlayerSkin(128, 320);
    for (auto &rod : road)
        if (checkPlayerCollision(rod->getCollisionSprite(), (sf::Vector2f){0, -32}))
            return;
    *builderPos += (32 * 0.92f);
    for (auto &rod : road)
        rod->moveWorldRoad();
}

void Player::movePlayerLeft(std::vector<std::shared_ptr<Road>> road) {
    if (_state == 0)
        changePlayerSkin(128, 448);
    if (_state == 1)
        changePlayerSkin(128, 416);
    if (_state == 2)
        changePlayerSkin(128, 480);
    for (auto &rod : road)
        if (checkPlayerCollision(rod->getCollisionSprite(), (sf::Vector2f){-32, 0}))
            return;
    changePlayerPos((sf::Vector2f){-32 * 0.92f, 0});
}

void Player::movePlayerRight(std::vector<std::shared_ptr<Road>> road) {
    if (_state == 0)
        changePlayerSkin(128, 64);
    if (_state == 1)
        changePlayerSkin(128, 32);
    if (_state == 2)
        changePlayerSkin(128, 96);
    for (auto &rod : road)
        if (checkPlayerCollision(rod->getCollisionSprite(), (sf::Vector2f){32, 0}))
            return;
    changePlayerPos((sf::Vector2f){32 * 0.92f, 0});
}

void Player::update(sf::Event &e, std::vector<std::shared_ptr<Road>> road, int *builderPos)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        movePlayerUp(road, builderPos);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        movePlayerLeft(road);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        movePlayerRight(road);
}

void Player::draw(sf::RenderWindow &w)
{
    w.draw(_sprite);
}
