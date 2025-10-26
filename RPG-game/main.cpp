#include<iostream>
#include<vector>
#include<SFML/Graphics.hpp>

int main() {

	sf::RenderWindow window(sf::VideoMode(800, 600), "Tetris");
	window.setFramerateLimit(60);

	sf::RectangleShape rectangle(sf::Vector2f(700.f, 500.f));
	rectangle.setPosition(10.f, 10.f);
	rectangle.setFillColor(sf::Color::Transparent);
	rectangle.setOutlineThickness(5.f);
	rectangle.setOutlineColor(sf::Color::White);
	float speed = 5.f;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);

		window.draw(rectangle);

		window.display();
	}
	return 0;
}