#include "bacteri.h"

#include <vector>
#include <math.h>
#include <iostream>

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
    this->position_ = pos;
    }

void bacteri::position(float x, float y) {
    sf::Vector2<float> pos{ x, y };
    this->position_ = pos;
    }

sf::Vector2<float> bacteri::position() const {
    return this->position_;
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

void bacteri::move() {
    int direction = rand() % 360;
    float x_pos = this->speed() * cos(direction);
    float y_pos = this->speed() * sin(direction);
    std::cout << "(" << x_pos << ", " << y_pos << ")@" << direction << std::endl;
    this->position(this->position_.x + x_pos, this->position_.y + y_pos);
    }
