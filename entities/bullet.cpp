//
//  bullet.cpp
//  spaceZ
//
//  Created by Mohammad Anas on 13/08/23.
//  Copyright © 2023 Mohammad Anas. All rights reserved.
//

#include <stdio.h>
#include "../utils/constants.h"
#include "../entities/bullet.h"

Bullet::Bullet(sf::Vector2f speed, int power, float x, float y, sf::Sprite sprite, Direction direction){
    this->x = x;
    this->y = y;
    this->power = power;
    this->speed = speed;
    this->width = BULLET_WIDTH;
    this->height = BULLET_HEIGHT;
    this->sprite = sprite;
    this->direction = direction;
}

void Bullet::update(){
    switch(this->direction){
        case Direction::UP :
            if((this->y + this->height) - this->speed.y >= 0){
                this->y -= this->speed.y;
            }
            break;
        case Direction::DOWN:
            if((this->y + this->speed.y) <= WINDOW_HEIGHT){
                this->y += this->speed.y;
            }
            break;
        case Direction::RIGHT:
            break;
        case Direction::LEFT:
            break;
    }
    this->sprite.setPosition(this->x, this->y);
}

sf::FloatRect Bullet::get_position(){
    return this->sprite.getLocalBounds();
}

float Bullet::getX(){
    return this->x;
}

float Bullet::getY(){
    return this->y;
}
