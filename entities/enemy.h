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
#include <SFML/Audio.hpp>
#include "../utils/constants.h"
#include "blast.h"

class Enemy{
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Texture blastT;
    sf::Sprite blastS;
    float height;
    float width;
    sf::Vector2f speed;
    int bullet_power;
    BuildType build_type;
    int health;
    float x;
    float y;
    bool alive;
    Blast *blast;
    bool isBlast;
    int blastCount;
    sf::Music blastMusic;
    
public:
    Enemy(float, float, BuildType);
    void update();
    void update_health(int);
    int get_health();
    sf::FloatRect get_current_position();
    float getX();
    float getY();
    void draw(sf::RenderWindow&);
    void drawBlast(sf::RenderWindow&);
    void killed();
    bool isAlive();
};

#endif /* enemy_h */
