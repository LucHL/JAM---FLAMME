/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** AScene
*/

#include "AScene.hpp"

AScene::AScene(std::string backgroundPath, sf::RenderWindow &win, sceneType t) : _window(win), _t(t)
{
    // _backgroundText.loadFromFile(backgroundPath);
    // _backgroundSprite.setTexture(_backgroundText);
    createSprite(sf::Vector2f(0,0), backgroundPath, sf::Vector2f(1.57,1.5));
}

AScene::~AScene() {}

void AScene::update(sf::Event &e)
{
    return;
}

void AScene::draw()
{
    for (auto i : _sprite)
        _window.draw(i);
    for (auto i : _text)
        _window.draw(i);
    for (auto i : _circle)
        _window.draw(i);
    for (auto i : _rect)
        _window.draw(i);
}

void AScene::initialize()
{
    createSprite(sf::Vector2f(0,0), "assets/map.png", sf::Vector2f(1.57,1.5));
    createText("hahaha", 50, sf::Color::Red, sf::Vector2f(100,100));
    createCircle(50, sf::Color::Green, sf::Vector2f(400,100));
}

sceneType &AScene::getType()
{
    return _t;
}

void AScene::createText(std::string text, int size, sf::Color color, sf::Vector2f pos)
{
    sf::Text to_draw;

    if (!_font.loadFromFile("assets/Arial.ttf")) {
        std::cerr << "Fail to load font." << std::endl;
        return;
    }
    to_draw.setFont(_font);
    to_draw.setString(text);
    to_draw.setCharacterSize(size);
    to_draw.setFillColor(color);
    to_draw.setPosition(pos.x, pos.y);
    _text.push_back(to_draw);
}

void AScene::createRect(sf::Color color, sf::Color border_color, float border_size,
    sf::Vector2f origin_pos, sf::Vector2f pos, float rotation_angle, sf::Vector2f size)
{
    sf::RectangleShape rect;

    rect.setFillColor(color);
    rect.setOutlineColor(border_color);
    rect.setOutlineThickness(border_size);
    rect.setOrigin(origin_pos.x, origin_pos.y);
    rect.setPosition(pos.x, pos.y);
    rect.setRotation(rotation_angle);
    rect.setSize(size);
    _rect.push_back(rect);
}

void AScene::createCircle(int ray, sf::Color color, sf::Vector2f position)
{
    sf::CircleShape circle(ray);

    circle.setFillColor(color);
    circle.setPosition(position);
    _circle.push_back(circle);
}

void AScene::createSprite(sf::Vector2f pos, std::string sprite_image, sf::Vector2f size)
{
    sf::Sprite sprite;

    _texture.loadFromFile(sprite_image);
    sprite.setTexture(_texture);
    sprite.setScale(size);
    sprite.setPosition(pos.x, pos.y);
    _sprite.push_back(sprite);
}
