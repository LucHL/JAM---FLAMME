/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** AScene
*/

#include "AScene.hpp"

AScene::AScene(std::string backgroundPath, sf::RenderWindow &win, sceneType t) : _window(win), _t(t)
{
    _backgroundText.loadFromFile(backgroundPath);
    _backgroundSprite.setTexture(_backgroundText);
}

AScene::~AScene() {}

void AScene::update(sf::Event &e) {
    return;
}

void AScene::draw()
{
    displaySprite(sf::Vector2f(0,0), "assets/startmenu.png", sf::Vector2f(20,20));
    displayCircle(50, sf::Color::Green, sf::Vector2f(10,10));
    displayText("ceci est un text (c fo)", 100, sf::Color::Blue, sf::Vector2f(100,100));
}

void AScene::initialize() {
    return;
}

sceneType &AScene::getType() {
    return _t;
}

void AScene::displayText(std::string text, int size, sf::Color color, sf::Vector2f pos)
{
    sf::Font font;
    sf::Text to_draw;

    if (!font.loadFromFile("assets/Arial.ttf")) {
        std::cerr << "Fail to load font." << std::endl;
        return;
    }
    to_draw.setFont(font);
    to_draw.setString(text);
    to_draw.setCharacterSize(size);
    to_draw.setFillColor(color);
    to_draw.setPosition(pos.x, pos.y);
    _window.draw(to_draw);
}

void AScene::displayRect(sf::Color color, sf::Color border_color, float border_size,
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
    _window.draw(rect);
}

void AScene::displayCircle(int ray, sf::Color color, sf::Vector2f position)
{
    sf::CircleShape circle(ray);

    circle.setFillColor(color);
    circle.setPosition(position);
    _window.draw(circle);
}

void AScene::displaySprite(sf::Vector2f pos, std::string sprite_image, sf::Vector2f size)
{
    sf::Sprite sprite;
    sf::Texture texture;

    texture.loadFromFile(sprite_image);
    sprite.setTexture(texture);
    sprite.setScale(size);
    sprite.setPosition(pos.x, pos.y);
    _window.draw(sprite);
}
