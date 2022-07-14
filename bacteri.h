#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class bacteri {
private:
   sf::CircleShape circle;
   std::string genome{ "xxxxxx" };
   float size_{ 10. };
   float speed_{ 5. };
   float distance_{ 50. };
   int direction{ 0 };
   
   sf::Vector2<float> position_{ 0., 0. };
   sf::Vector2<float> position2_{ 0., 0. };
   sf::Color color_{ 255, 255, 255, 255 };

   void randomColor();


public:
   bacteri(std::vector<bacteri>& list, sf::Vector2<float> pos, float size, bool randC = false);
   void size(float);
   void speed(float);
   void position(sf::Vector2<float>);
   void position(float x, float y);
   void position2(sf::Vector2<float>);
   void position2(float x, float y);
   void color(sf::Color);

   float size() const;
   float speed() const;
   sf::Vector2<float> position() const;
   sf::Vector2<float> position2() const;
   sf::Color color() const;
   sf::CircleShape shape() const;

   void moveRand();
   std::vector<sf::Vector2<float>> move();
   };