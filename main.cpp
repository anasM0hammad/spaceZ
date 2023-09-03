#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "utils/constants.h"
#include "entities/spaceship.h"
#include "entities/bullet.h"
#include "entities/enemy.h"
#include "utils/utilities.h"

#include <vector>
#include <random>

#include <iostream>

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"

int main(int, char const**)
{
    // Game Metrics
    GameState state = GameState::READY;
    int score = 0;
    int onScreenEnemyCount = 0;
    int onScreenEnemies = 3;
    int enemyCrossCount = 0;
    // Spaceship Initialization
    Spaceship *spaceship = new Spaceship((WINDOW_WIDTH - 300) / 2, WINDOW_HEIGHT - 250);
    std::vector<Bullet*> bullets = {};
    
    std::random_device rd;
    std::mt19937 mt(time(0));
    std::uniform_real_distribution<float> range(0.0, WINDOW_WIDTH - 100);
    std::uniform_int_distribution<int> boolGen(1,2500);
    int gameEndCount = 0;
    std::vector<Enemy*> enemies = {};
//    Bullet *bullet = new Bullet({0, SPACESHIP_BULLET_SPEED}, SPACESHIP_POWER, WINDOW_WIDTH/2, WINDOW_HEIGHT/2, Direction::UP);
//    Bullet *enemyBullet = new Bullet({0, 0.1}, 1, WINDOW_WIDTH/3, WINDOW_HEIGHT/3, Direction::DOWN);
    
    
    
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
    
    sf::Music musicBullet;

    // Start the game loop
    while (window.isOpen())
    {
        if(state == GameState::READY){
            text.setString(GAME_START_MSG);
            text.setPosition((WINDOW_WIDTH - 300) / 2, (WINDOW_HEIGHT - 200) / 2);
            score = 0;
            enemyCrossCount = 0;
            onScreenEnemyCount = 0;
            onScreenEnemies = 3;
            gameEndCount = 0;
            
            makeNull(enemies);
//            makeNull(bullets);
            bullets.clear();
            enemies.clear();
            
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
            scoreText.setString("Score : " + std::to_string(score));
            
            enemyCleanup(enemies);
            
            if(score > 50 && onScreenEnemies == 3){
                onScreenEnemies++;
            }
            
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
                    
                    else if(event.key.code == sf::Keyboard::Space){
                        Bullet *bullet = new Bullet({0, SPACESHIP_BULLET_SPEED}, SPACESHIP_POWER, spaceship->get_centerX(), spaceship->getY(), Direction::UP);
                        bullets.push_back(bullet);
                        
                        musicBullet.openFromFile(ASSETSPATH + "laser-spaceship-sound.ogg");
                        musicBullet.play();
                    }
                }
                
                if(event.type == sf::Event::MouseMoved){
                    sf::Vector2i mouseCoordinates = sf::Mouse::getPosition(window);
                    spaceship->set_position(mouseCoordinates.x, spaceship->getY());
                }
                
            }
            
            if(boolGen(mt) == 1 && onScreenEnemyCount < onScreenEnemies){
                float randX = range(mt);
                Enemy *enemy = new Enemy(randX, 0, BuildType::BEGINNER);
                enemies.push_back(enemy);
                onScreenEnemyCount++;
                std::cout<<std::to_string(enemies.size());
            }
            
            for(auto bullet: bullets){
                bullet->update();
            }
            
            for(auto enemy: enemies){
                enemy->update();
            }
            
            for(auto enemy: enemies){
                if(enemy->isAlive()){
                    for(auto bullet: bullets){
                        if(bullet->getY() > 0){
                            if(enemy->get_current_position().intersects(bullet->get_position())){
                                // KILLED
                                enemy->update_health(-1*bullet->getPower());
                                if(enemy->get_health() <= 0){
                                    enemy->killed();
                                    score++;
                                    onScreenEnemyCount--;
                                }
                            }
                        }
                    }
                }
            }
            
            window.clear();
            
            window.draw(background);
            window.draw(scoreText);
            spaceship->draw(window);
            
            for(auto bullet: bullets){
                bullet->draw(window);
            }
            
            for(auto enemy: enemies){
                if(enemy->isAlive()){
                    enemy->draw(window);
                    if(enemy->getY() > WINDOW_HEIGHT){
                        enemyCrossCount++;
                        score--;
                        enemy->killed();
                    }
                    
                    if(spaceship->get_current_position().intersects(enemy->get_current_position())){
                        enemy->killed();
                        gameEndCount++;
                        if(gameEndCount > 1){
                            state = GameState::COMPLETED;
                        }
                    }
                }
                else{
                    enemy->drawBlast(window);
                }
            }
            
            
            window.display();
            
            if(enemyCrossCount > onScreenEnemies){
                state = GameState::COMPLETED;
            }
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
            sf::Event event;
            text.setString(GAME_COMPLETED_STRING);
            text.setPosition((WINDOW_WIDTH - 600) / 2, (WINDOW_HEIGHT - 200) / 2);
            
            sf::Text scoreDisplay("Final Score : " + std::to_string(score), font, 50);
            scoreDisplay.setFillColor(sf::Color::White);
            scoreDisplay.setPosition((WINDOW_WIDTH - 600) / 2, (WINDOW_HEIGHT - 400) / 2);
            
            while(window.pollEvent(event)){
                
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                
                if(event.type == sf::Event::MouseButtonReleased){
                    state = GameState::READY;
                }
                
                if (event.type == sf::Event::KeyPressed) {
                    if(event.key.code == sf::Keyboard::Escape){
                        window.close();
                    }
                    else if(event.key.code == sf::Keyboard::Enter){
                        state = GameState::READY;
                    }
                }
            }
            
            window.clear();
            
            window.draw(background);
            window.draw(text);
            window.draw(scoreDisplay);
            window.display();
        }
        else{
            // INVALID STATE
            return EXIT_FAILURE;
        }
        
    }

    return EXIT_SUCCESS;
}
