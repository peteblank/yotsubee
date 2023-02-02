#include "config.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

/* Basic project example */

int main() {

     sf::Texture texture;
if (!texture.loadFromFile("mario.png"))
{
    // error...
    cout<<"failed";
}
sf::Sprite sprite;
sprite.setTexture(texture);

cout << "Version " << myproject_VERSION_MAJOR << "." << myproject_VERSION_MINOR << endl;

    sf::RenderWindow App(sf::VideoMode(800, 600), "SFML_Project");

    while (App.isOpen()) {
        sf::Event Event;
              
        while (App.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed)
        
	App.close();
        }
	App.draw(sprite);    

        App.display();
    }
}
