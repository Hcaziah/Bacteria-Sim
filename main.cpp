#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h> // rand

#include "bacteri.cpp"

int windowWidth = 1440;
int windowHeight = 900;

int main() {
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Bacteria Sim");
    window.setFramerateLimit(144);

    bool lMouse{ false };
    bool num1{ false };
    float mWheelSize{ 10.0 };

    std::vector<bacteri> colony{};

    while (window.isOpen()) {
        // get the current mouse position in the window
        sf::Vector2i pixelPos = sf::Mouse::getPosition(window);

        // convert it to world coordinates
        sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                window.close();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !lMouse) {
                lMouse = true;
                }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && colony.size() > 0) {
                window.clear();
                std::cout << "Removed " << colony.size() << " bacteri." << std::endl;
                colony.clear();
                }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && !num1) {
                for (int i = 0; i < 100; i++) {
                    sf::Vector2<float> rand_pos(rand() % windowWidth, rand() % windowHeight);
                    bacteri(colony, rand_pos, rand() % 10 + 10, true);
                    }
                num1 = true;
                }
            if (event.type == event.MouseButtonReleased && lMouse) {
                lMouse = false;
                }
            if (event.type == event.KeyReleased && num1) {
                num1 = false;
                }
            }


        window.clear();
        for (auto bacteri : colony) {
            bacteri.move();
            window.draw(bacteri.shape());
            }
        window.display();
        }

    return 0;
    }
