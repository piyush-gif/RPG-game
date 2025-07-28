#include<iostream>
#include<SFML/Graphics.hpp>

class  Person
{
public:
	int posx, posy;
	std::string health;
	sf::Sprite shape;
	sf::Texture texture;

	Person(int x, int y) {
		posx = x;
		posy = y;
		if (!texture.loadFromFile("D:/RPG-game/x64/Debug/mage.png")) {
			std::cout << "Error: Could not load player.png\n";
		}
		shape.setTexture(texture);
		shape.setPosition(posx, posy);
	}

	void draw(sf::RenderWindow& window) {
		window.draw(shape);
	}

	void move(int deltaX, int deltaY) {
		posx += deltaX; 
		posy += deltaY; 
		shape.setPosition(posx, posy); 
	}
};
