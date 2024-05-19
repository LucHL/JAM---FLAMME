/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** AScene
*/

#include "AScene.hpp"

AScene::AScene(std::string backgroundPath, sf::RenderWindow &win, sceneType t) : _window(win), _t(t)
{
    _button = Btn("assets/button/new_play.png", sf::Vector2f(100,100), sf::Vector2f(300,108));
    _texture.loadFromFile(backgroundPath);
    _sprite.setTexture(_texture);
    _sprite.setScale(sf::Vector2f(1.7,1.5));
}

AScene::~AScene() {}

void AScene::update(sf::Event &e)
{
    return;
}

void AScene::draw()
{
    // for (auto i : _sprite)
    //     _window.draw(i);
    // for (auto i : _text)
    //     _window.draw(i);
    // for (auto i : _circle)
    //     _window.draw(i);
    // for (auto i : _rect)
    //     _window.draw(i);
    _window.draw(_sprite);
}

void AScene::initialize()
{
    
}

sceneType &AScene::getType()
{
    return _t;
}

// void AScene::createText(std::string text, int size, sf::Color color, sf::Vector2f pos)
// {
//     sf::Text to_draw;

//     if (!_font.loadFromFile("assets/Arial.ttf")) {
//         std::cerr << "Fail to load font." << std::endl;
//         return;
//     }
//     to_draw.setFont(_font);
//     to_draw.setString(text);
//     to_draw.setCharacterSize(size);
//     to_draw.setFillColor(color);
//     to_draw.setPosition(pos.x, pos.y);
//     _text.push_back(to_draw);
// }

// void AScene::createRect(sf::Color color, sf::Color border_color, float border_size,
//     sf::Vector2f origin_pos, sf::Vector2f pos, float rotation_angle, sf::Vector2f size, bool NeedCenter)
// {
//     sf::RectangleShape rect;
//     sf::FloatRect HitBox;

//     rect.setFillColor(color);
//     rect.setOutlineColor(border_color);
//     rect.setOutlineThickness(border_size);
//     rect.setOrigin(origin_pos.x, origin_pos.y);
//     if (NeedCenter) {
//         HitBox = rect.getLocalBounds();
//         rect.setOrigin(HitBox.width / 2, HitBox.height / 2);
//     }
//     rect.setPosition(pos.x, pos.y);
//     rect.setRotation(rotation_angle);
//     rect.setSize(size);
//     _rect.push_back(rect);
// }

// void AScene::createCircle(int ray, sf::Color color, sf::Vector2f position)
// {
//     sf::CircleShape circle(ray);

//     circle.setFillColor(color);
//     circle.setPosition(position);
//     _circle.push_back(circle);
// }

// void AScene::createSprite(sf::Vector2f pos, std::string sprite_image, sf::Vector2f size, bool NeedCenter)
// {
//     sf::Texture texture;
//     sf::Sprite sprite;
//     sf::FloatRect HitBox;

//     texture.loadFromFile(sprite_image);
//     sprite.setScale(size);
//     if (NeedCenter) {
//         HitBox = sprite.getLocalBounds();
//         sprite.setOrigin(HitBox.width / 2, HitBox.height / 2);
//     }
//     sprite.setPosition(pos.x, pos.y);
//     // _sprite[sprite] = (texture, sprite_image);
//     // _sprite.push_back(sprite);
// }
