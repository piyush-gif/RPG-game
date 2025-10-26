#include<iostream>
#include<vector>
#include<SFML/Graphics.hpp>

int main() {

	sf::RenderWindow window(sf::VideoMode(800, 600), "Tetris");

	sf::RectangleShape rectangle(sf::Vector2f(120.f, 60.f));
	rectangle.setFillColor(sf::Color::White);
	rectangle.setPosition(100.f, 200.f);


	sf::CircleShape circle(50.f);
	circle.setFillColor(sf::Color::White);
	circle.setPosition(300.f, 180.f);

	float speed = 5.f;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			rectangle.move(0.f, -speed);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			rectangle.move(0.f, speed);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			rectangle.move(-speed, 0.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			rectangle.move(speed, 0.f);

		window.clear(sf::Color::Black);

		window.draw(rectangle);
		window.draw(circle);

		window.display();
	}

	

	return 0;
}