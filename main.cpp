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
    window.setFramerateLimit(100);

    bool lMouse{ false };
    bool num1{ false };
    bool num2{ false };
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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && !num2) {
                for (int i = 0; i < 2; i++) {
                    sf::Vector2<float> rand_pos(rand() % windowWidth, rand() % windowHeight);
                    bacteri(colony, rand_pos, rand() % 10 + 10, true);
                    }
                num2 = true;
                }
            if (event.type == event.MouseButtonReleased && lMouse) {
                lMouse = false;
                }
            if (event.type == event.KeyReleased && num1) {
                num1 = false;
                }
            if (event.type == event.KeyReleased && num2) {
                num2 = false;
                }

            }


        window.clear();
        int itt{ 0 };
        std::cout << std::endl << std::string(20, '=') << std::endl;
        for (auto bacteri : colony) {
            bacteri.moveRand();
            std::cout << itt << " - (" << bacteri.position().x << ", " << bacteri.position().y << ") -> (" << bacteri.position2().x << ", " << bacteri.position2().y << ")" << std::endl;
            //bacteri.move();
            window.draw(bacteri.shape());
            itt++;
            }
        window.display();
        }

    return 0;
    }
