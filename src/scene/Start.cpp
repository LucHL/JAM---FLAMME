/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** Start
*/

#include "Start.hpp"

Start::Start(std::string backgroundPath, sf::RenderWindow &win) : _window(win)
{
    _backgroundText.loadFromFile(backgroundPath);
    _backgroundSprite.setTexture(_backgroundText);
    _t = sceneType::MAINMENU;
}

Start::~Start() {}

void Start::update(sf::Event &e) {
    return;
}

void Start::draw(sf::RenderWindow &w) {
    w.draw(_backgroundSprite);
}

void Start::initialize() {
    return;
}

sceneType &Start::getType() {
    return _t;
}

void Start::displayText(std::string text, int size, sf::Color color, sf::Vector2f pos)
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

void Start::displayRect(sf::Color color, sf::Color border_color, float border_size,
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

void Start::displayCircle(int ray, sf::Color color, sf::Vector2f position)
{
    sf::CircleShape circle(ray);

    circle.setFillColor(color);
    circle.setPosition(position);
    _window.draw(circle);
    // TODO texture ???
}

void Start::displaySprite(sf::Vector2f pos, std::string sprite_image, sf::Vector2f size)
{
    sf::Sprite sprite;
    sf::Texture texture;

    texture.loadFromFile(sprite_image);
    sprite.setTexture(texture);
    sprite.setScale(size);
    sprite.setPosition(pos.x, pos.y);
    _window.draw(sprite);
}
