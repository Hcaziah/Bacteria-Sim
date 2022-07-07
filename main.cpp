#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "blob.cpp"

int main() {
    sf::ContextSettings settings;
    // settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 800), "Bacteria Sim");
    window.setFramerateLimit(100);

    std::vector<blob> shape_list{};

    while (window.isOpen()) {
        sf::Event event;
        sf::Vector2<int> mousePos = sf::Mouse::getPosition();
        bool lMouse{false};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                window.close();
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && shape_list.size() > 0) {
                window.clear();
                std::cout << "Shape list was cleared \n removed " << shape_list.size() << " circles." << std::endl;
                shape_list.clear();
            } else if (event.type == event.MouseButtonReleased) {  // lMouse &&
                // get the current mouse position in the window
                sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
                //pixelPos.x -= 20;
                //pixelPos.y -= 20;
                std::cout << "Circle spawned @ (";
                std::cout << pixelPos.x << ", " << pixelPos.y << ")" << std::endl;

                // convert it to world coordinates
                sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);

                blob(worldPos, shape_list);
                lMouse = false;
                std::cout << shape_list.size() << std::endl;
                // blob(mousePos);
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