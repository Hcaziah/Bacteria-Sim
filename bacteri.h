#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class bacteri {
private:
   sf::CircleShape circle;
   std::string genome{ "xxxxxx" };
   float size_{ 10. };
   float speed_{ 10. };
   sf::Vector2<float> position_{ 0., 0. };
   sf::Color color_{ 255, 255, 255, 255 };

   void randomColor();


public:
   bacteri(std::vector<bacteri>& list, sf::Vector2<float> pos, float size, bool randC = false);
   void size(float);
   void speed(float);
   void position(sf::Vector2<float>);
   void position(float x, float y);
   void color(sf::Color);

   float size() const;
   float speed() const;
   sf::Vector2<float> position() const;
   sf::Color color() const;
   sf::CircleShape shape() const;

   void move();
   };