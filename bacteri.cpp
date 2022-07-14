#include "bacteri.h"

#include <vector>
#include <math.h>
#include <iostream>
#include <map>

bacteri::bacteri(std::vector<bacteri>& list, sf::Vector2<float> pos, float size, bool randC) {
    this->position_ = pos;
    this->size_ = size;
    sf::CircleShape circle(this->size_, 32);
    circle.setPosition(this->position_);
    if (randC) {
        this->randomColor();
        }
    circle.setFillColor(this->color_);
    circle.setOrigin(this->size_, this->size_);
    this->circle = circle;
    list.push_back(*this);
    }

void bacteri::randomColor() {
    this->color_ = sf::Color(rand() % 256, rand() % 256, rand() % 256, 255);
    }

void bacteri::size(float size) {
    this->size_ = size;
    }

float bacteri::size() const {
    return this->size_;
    }

void bacteri::speed(float speed) {
    this->speed_ = speed;
    }

float bacteri::speed() const {
    return this->speed_;
    }

void bacteri::position(sf::Vector2<float> pos) {
    this->circle.setPosition(pos);
    }

void bacteri::position(float x, float y) {
    this->circle.setPosition(x, y);
    }

sf::Vector2<float> bacteri::position() const {
    return this->circle.getPosition();
    }

void bacteri::position2(sf::Vector2<float> pos) {
    this->position2_ = pos;
    }

void bacteri::position2(float x, float y) {
    sf::Vector2<float> temp{ x, y };
    this->position2(temp);
    }

sf::Vector2<float> bacteri::position2() const {
    return this->position2_;
    }

void bacteri::color(sf::Color color) {
    this->color_ = color;
    }

sf::Color bacteri::color() const {
    return this->color_;
    }

sf::CircleShape bacteri::shape() const {
    return this->circle;
    }

void bacteri::moveRand() {
    int direction = rand() % 360;
    this->direction = direction;
    const sf::Vector2<float>& current_pos = this->position();
    this->position2_.x = current_pos.x + (this->distance_ * cos(direction));
    this->position2_.y = current_pos.y + (this->distance_ * sin(direction));
    }

std::vector<sf::Vector2<float>> bacteri::move() {
    std::vector<sf::Vector2<float>> point_map{};
    for (int i = 0; i < 10; i++) {
        float x_pos = x_pos * (i / 10);
        float y_pos = y_pos * (i / 10);
        point_map.push_back();
        }
    }
