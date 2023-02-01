#include "config.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

/* Basic project example */

int main() {

    /* Code adapted from the SFML 2 "Window" example */

    cout << "Version " << myproject_VERSION_MAJOR << "." << myproject_VERSION_MINOR << endl;

    sf::Window App(sf::VideoMode(800, 600), "SFML_Project");

    while (App.isOpen()) {
        sf::Event Event;
        while (App.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed)
            App.close();
        }
        App.display();
    }
}
