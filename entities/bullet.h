//
//  bullet.h
//  spaceZ
//
//  Created by Mohammad Anas on 13/08/23.
//  Copyright © 2023 Mohammad Anas. All rights reserved.
//

#ifndef bullet_h
#define bullet_h

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Bullet{
private:
    sf::Sprite sprite;
    sf::Texture texture;
    float width;
    float height;
    sf::Vector2f speed;
    int power;
    float x;
    float y;
    Direction direction;
    
public:
    Bullet(sf::Vector2f, int, float, float, Direction);
    void update();
    sf::FloatRect get_position();
    float getX();
    float getY();
    void draw(sf::RenderWindow&);
    int getPower();
};

#endif /* bullet_h */
