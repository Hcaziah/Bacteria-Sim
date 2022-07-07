#include "blob.h"

#include <SFML/Graphics.hpp>
#include <vector>

blob::blob(sf::Vector2<float> pos, std::vector<blob>& shape_list, float size) {
    this->pos = pos;
    this->size = size;
    sf::CircleShape circle(this->size);
    this->circle = circle;
    this->circle.setPosition(this->pos.x, this->pos.y);
    this->circle.setFillColor(this->color);
    this->circle.setOrigin(this->size, this->size);
    this->circle.setPointCount(64);
    shape_list.push_back(*this);
    }

void blob::set_position(const sf::Vector2<float>& pos) { this->pos = pos; }
void blob::set_color(sf::Color color) { this->color = color; }
void blob::set_size(float size) { this->size = size; }
void blob::set_speed(float speed) { this->speed = speed; }

sf::Vector2<float> blob::get_position() const { return this->pos; }
sf::Color blob::get_color() const { return this->color; }
float blob::get_size() const { return this->size; };
float blob::get_speed() const { return this->speed; };
sf::CircleShape blob::get_circle() { return this->circle; }

