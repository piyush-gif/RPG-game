#include <SFML/Graphics.hpp>
#include "Person.h"
#include "Platform.h"
int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "RPG Game");

	Person player(100, 100);
	Platform platform(0, 500, 800, 50);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::A) {
					player.move(-10, 0);
				}
				if (event.key.code == sf::Keyboard::D) {
					player.move(10, 0);
				}
				if (event.key.code == sf::Keyboard::W) {
					player.move(0, -10);
				}
				if (event.key.code == sf::Keyboard::S) {
					player.move(0, 10);
				}
			}
		}
		window.clear();
		player.draw(window);
		platform.draw(window);
		window.display();

	}
	return 0;
}