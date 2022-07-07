#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "blob.cpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Bacteria Sim");

    window.setFramerateLimit(100);
    bool lMouse{false};

    std::vector<blob> shape_list{};

    while (window.isOpen()) {
        sf::Event event;
        sf::Vector2<int> mousePos = sf::Mouse::getPosition();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                window.close();
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && shape_list.size() > 0) {
                window.clear();
                std::cout << "Removed " << shape_list.size() << " circles." << std::endl;
                shape_list.clear();
            } else if (event.type == event.MouseButtonReleased && lMouse) { 
                // get the current mouse position in the window
                sf::Vector2i pixelPos = sf::Mouse::getPosition(window);

                // convert it to world coordinates
                sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);

                blob(worldPos, shape_list);
                lMouse = false;
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                lMouse = true;
            }
        }
        window.clear();
        for (auto circ : shape_list) window.draw(circ.get_circle());
        window.display();
    }

    return 0;
}