#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Platform {
public:
    int posx, posy;
    std::vector<sf::Sprite> shapes; // Store multiple sprites for tiling
    sf::Texture texture;

    Platform(int x, int y, int width, int height) {
        posx = x;
        posy = y;
        if (!texture.loadFromFile("D:/RPG-game/x64/assets/ground.png")) {
            std::cout << "Error: Could not load platform.png\n";
        }

        // Calculate number of sprites needed (assuming sprite is 32 pixels wide)
        int spriteWidth = texture.getSize().x; // Get actual sprite width
        int numSprites = (width + spriteWidth - 1) / spriteWidth; // Round up

        // Create and position sprites
        for (int i = 0; i < numSprites; ++i) {
            sf::Sprite sprite;
            sprite.setTexture(texture);
            sprite.setPosition(posx + i * spriteWidth, posy); // Tile along x
            sprite.setScale(1.0f, static_cast<float>(height) / texture.getSize().y); // Scale height
            shapes.push_back(sprite);
        }
    }

    void draw(sf::RenderWindow& window) {
        for (const auto& sprite : shapes) {
            window.draw(sprite); // Draw each sprite
        }
    }
};