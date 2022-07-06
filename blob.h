#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class blob {
   private:
    std::vector<int> rgb_{255, 180, 0};
    sf::Vector2<float> pos{0., 0.};
    sf::Color color{255, 180, 0};
    int speed = 2;
    int size = 10;
    void gravityUpdate();

   public:
    blob(sf::Vector2<float> pos, std::vector<sf::CircleShape> &shape_list);
};
