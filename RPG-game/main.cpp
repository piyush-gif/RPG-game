#include <SFML/Graphics.hpp>

class Shooter {
private:
    sf::ConvexShape shape;

public:
    Shooter() {
        shape.setPointCount(3); 
        shape.setPoint(0, sf::Vector2f(0.f, 0.f));    
        shape.setPoint(1, sf::Vector2f(-9.f, 19.f));  
        shape.setPoint(2, sf::Vector2f(9.f, 19.f));  
        shape.setOrigin(0.f, 0.f);                     
        shape.setPosition(410.f, 300.f);

    }

    void draw(sf::RenderWindow& window) { // to draw the traingle shape
        window.draw(shape);
    }

    void update(float dt) {
        float speed = 200.f;   // pixel per second
        float rotationSpeed = 180.f; 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            shape.rotate(-rotationSpeed * dt);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            shape.rotate(rotationSpeed * dt);

        // Move forward/backward along tip direction
        float angle = shape.getRotation() - 90.f; // adjust so tip points upward
        float rad = angle * 3.14159265f / 180.f;  // convert to radians

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            shape.move(std::cos(rad) * speed * dt, std::sin(rad) * speed * dt);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            shape.move(-std::cos(rad) * speed * dt, -std::sin(rad) * speed * dt);
    }


};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Astroid game");
    window.setFramerateLimit(60);
    sf::Clock clock;

    Shooter shooter;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        float dt = clock.restart().asSeconds();


        window.clear(sf::Color::Black);
        shooter.draw(window);
        shooter.update(dt);
        window.display();
    }

    return 0;
}
