//
//  enemy.h
//  spaceZ
//
//  Created by Mohammad Anas on 12/08/23.
//  Copyright © 2023 Mohammad Anas. All rights reserved.
//

#ifndef enemy_h
#define enemy_h
#include <SFML/Graphics.hpp>
#include "../utils/constants.h"

class Enemy{
private:
    sf::Sprite sprite;
    float height;
    float width;
    sf::Vector2f speed;
    int bullet_power;
    BuildType build_type;
    int health;
    float x;
    float y;
    
public:
    Enemy(float, float, sf::Sprite, BuildType, sf::Vector2f);
    void update();
    void update_health(int);
    int get_health();
    sf::FloatRect get_current_position();
    float getX();
    float getY();
};

#endif /* enemy_h */
