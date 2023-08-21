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

class Bullet{
private:
    sf::Sprite sprite;
    float width;
    float height;
    sf::Vector2f speed;
    int power;
    float x;
    float y;
    Direction direction;
    
public:
    Bullet(sf::Vector2f, int, float, float, sf::Sprite, Direction);
    void update();
    sf::FloatRect get_position();
    float getX();
    float getY();
};

#endif /* bullet_h */
