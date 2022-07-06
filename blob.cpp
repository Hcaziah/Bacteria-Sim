#include "blob.h"

#include <SFML/Graphics.hpp>
#include <vector>

blob::blob(sf::Vector2<float> pos, std::vector<sf::CircleShape> &shape_list) {
    this->pos = pos;
    sf::CircleShape circle(this->size);
    circle.setPosition(this->pos.x, this->pos.y);
    circle.setFillColor(this->color);
    shape_list.push_back(circle);
    this->gravityUpdate();
}

void blob::gravityUpdate() {
    std::cout << this->pos.y;
    for (int t = 0; this->pos.y > -5; t++) {
        this->pos.y -= this->pos.y * 0.981 * t;
    }
    std::cout << " " << this->pos.y << std::endl;
}

