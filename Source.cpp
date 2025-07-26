#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 100), "SFML window");
    vector <sf::CircleShape> circles;
    int i = 0;
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::CircleShape circle(50.f);
                    circle.setFillColor(sf::Color::Green);
                    circle.setPosition(100 * i, 0);
                    circles.push_back(circle);
                    i++;
                }
                if (event.mouseButton.button == sf::Mouse::Right) {

                    circles.pop_back();
                    i--;
                }
            }
        }


        window.clear();
        for (auto i : circles) {
            window.draw(i);
        }

        window.display();
    }

    return EXIT_SUCCESS;
}
