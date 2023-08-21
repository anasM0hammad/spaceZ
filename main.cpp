#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "utils/constants.h"
#include "entities/spaceship.h"

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"

int main(int, char const**)
{
    // Game Metrics
    GameState state = GameState::READY;
    int score = 0;
    
    // Spaceship Initialization
    sf::Vector2f spaceshipSpeed = {20.0, 0};
    Spaceship *spaceship = new Spaceship(spaceshipSpeed, (WINDOW_WIDTH - 300) / 2, WINDOW_HEIGHT - 250);
    
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SpaceZ");

    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(ASSETSPATH + "logo.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile(ASSETSPATH + "background.jpeg")) {
        return EXIT_FAILURE;
    }
    sf::Sprite background(texture);

    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(ASSETSPATH + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Text text(GAME_START_MSG , font, 50);
    text.setFillColor(sf::Color::White);
    text.setPosition((WINDOW_WIDTH - 300) / 2, (WINDOW_HEIGHT - 200) / 2);
    
    sf::Text scoreText("Score : " + std::to_string(score) , font, 15);
    text.setFillColor(sf::Color::White);

    // Load a music to play
    sf::Music music;
    if (!music.openFromFile(ASSETSPATH + "background_music.ogg")) {
        return EXIT_FAILURE;
    }

    // Play the music
    music.setLoop(true);
    music.play();

    // Start the game loop
    while (window.isOpen())
    {
        if(state == GameState::READY){
            text.setString(GAME_START_MSG);
            score = 0;
            sf::Event event;
            while (window.pollEvent(event))
            {
                // Close window: exit
                if (event.type == sf::Event::Closed) {
                    window.close();
                }

                // Escape pressed: exit
                if (event.type == sf::Event::KeyPressed) {
                    if(event.key.code == sf::Keyboard::Escape){
                        window.close();
                    }
                    else if(event.key.code == sf::Keyboard::Enter){
                        state = GameState::RUNNING;
                    }
                }
                
                if(event.type == sf::Event::MouseButtonReleased){
                    state = GameState::RUNNING;
                }
                
            }
            
            // Clear screen
            window.clear();

            // Draw the sprite
            window.draw(background);

            // Draw the string
            window.draw(text);

            // Update the window
            window.display();
        }
        
        
        else if(state == GameState::RUNNING){
            sf::Event event;
            scoreText.setPosition(WINDOW_WIDTH - (WINDOW_WIDTH / 12), 20);
            while (window.pollEvent(event))
            {
                // Close window: exit
                if (event.type == sf::Event::Closed) {
                    window.close();
                }

                // Escape pressed: exit
                if (event.type == sf::Event::KeyPressed) {
                    if(event.key.code == sf::Keyboard::Escape){
                        window.close();
                    }
                    
                    else if(event.key.code == sf::Keyboard::P){
                        state = GameState::PAUSED;
                    }
                    
                    else if(event.key.code == sf::Keyboard::Left){
                        spaceship->move_left();
                    }
                    
                    else if(event.key.code == sf::Keyboard::Right){
                        spaceship->move_right();
                    }
                }
            }
            
            window.clear();
            window.draw(background);
            window.draw(scoreText);
            spaceship->draw(window);
            window.display();
        }
        
        else if(state == GameState::PAUSED){
            sf::Event event;
            text.setString(GAME_PAUSED_MSG);
            text.setPosition((WINDOW_WIDTH - 500) / 2, (WINDOW_HEIGHT - 200) / 2);
            while (window.pollEvent(event))
            {
                // Close window: exit
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                
                if(event.type == sf::Event::MouseButtonReleased){
                    state = GameState::RUNNING;
                }

                // Escape pressed: exit
                if (event.type == sf::Event::KeyPressed) {
                    if(event.key.code == sf::Keyboard::Escape){
                        window.close();
                    }
                    else if(event.key.code == sf::Keyboard::Enter){
                        state = GameState::RUNNING;
                    }
                }
            }

            window.clear();
            window.draw(background);
            window.draw(text);
            window.display();
        }
        else if(state == GameState::COMPLETED){
            
        }
        else{
            // INVALID STATE
            return EXIT_FAILURE;
        }
        
    }

    return EXIT_SUCCESS;
}
