//
//  spaceship.h
//  spaceZ
//
//  Created by Mohammad Anas on 11/08/23.
//  Copyright © 2023 Mohammad Anas. All rights reserved.
//

#ifndef spaceship_h
#define spaceship_h
#include <SFML/Graphics.hpp>

class Spaceship {
private:
    sf::Vector2f speed;
    int health;
    int bullet_power;
    float x;
    float y;
    float height;
    float width;
    sf::Sprite sprite;
    sf::Texture texture;
    
public:
    Spaceship(sf::Vector2f, float, float);
    void reset(float, float);
    void set_position(float, float);
    void move_left();
    void move_right();
    sf::FloatRect get_current_position();
    float get_centerX();
    void update_health(int);
    int get_health();
    float getX();
    float getY();
    void draw(sf::RenderWindow& window);
};

#endif /* spaceship_h */
