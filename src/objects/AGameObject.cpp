/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** AGameObject
*/

#include "../../include/objects/AGameObject.hpp"

AGameObject::AGameObject(sf::RenderWindow &win, sf::Event &event) : _window(win), _event(event)
{
    createWindow();
}

AGameObject::~AGameObject() {}

void AGameObject::createWindow()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    _window.create(sf::VideoMode(1920, 1080), "FLAMME", sf::Style::Default, settings);
}

void AGameObject::displayText(std::string text, int size, sf::Color color, sf::Vector2f pos)
{
    sf::Font font;
    sf::Text to_draw;

    if (!font.loadFromFile("src/objects/Arial.ttf")) {
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

void AGameObject::displayRect(sf::Color color, sf::Color border_color, float border_size,
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

void AGameObject::displayCircle(int ray, sf::Color color, sf::Vector2f position)
{
    sf::CircleShape circle(ray);

    circle.setFillColor(color);
    circle.setPosition(position);
    _window.draw(circle);
    // TODO texture ???
}

void AGameObject::displaySprite(sf::Vector2f pos, std::string sprite_image, sf::Vector2f size)
{
    sf::Sprite sprite;
    sf::Texture texture;

    texture.loadFromFile(sprite_image);
    sprite.setTexture(texture);
    sprite.setScale(size);
    sprite.setPosition(pos.x, pos.y);
    _window.draw(sprite);
}

void AGameObject::playMusic(std::string filename)
{
    sf::Music music;

    if (!music.openFromFile(filename)) {
        std::cerr << "Fail to load music." << std::endl;
        return;
    }
    music.play();
}

void AGameObject::handleEvent()
{
    if (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            _window.close();
        }
    }
}
