//
//  spaceship.cpp
//  spaceZ
//
//  Created by Mohammad Anas on 11/08/23.
//  Copyright © 2023 Mohammad Anas. All rights reserved.
//

#include "spaceship.h"
#include "../utils/constants.h"

Spaceship::Spaceship(float height, float width, sf::Vector2f speed, sf::Sprite sprite, float x, float y){
    this->height = height;
    this->width = width;
    this->speed = speed;
    this->sprite = sprite;
    this->x = x;
    this->y = y;
    this->health = START_SPACESHIP_HEALTH;
    this->bullet_power = START_SPACESHIP_BULLET_POWER;
    sprite.setPosition(this->x, this->y);
    
}

void Spaceship::move_left(){
    if(this->x - this->speed.x <= 0){
        this->x = 0;
    }
    else{
        this->x = this->x - this->speed.x;
    }
    this->sprite.setPosition(this->x, this->y);
    return;
}

void Spaceship::move_right(){
    float cornerX = this->x + this->width;
    if(cornerX + this->speed.x >= WINDOW_WIDTH){
        this->x = WINDOW_WIDTH - this->width;
    }
    else{
        this->x = this->x + this->speed.x;
    }
    this->sprite.setPosition(this->x, this->y);
    return;
}

sf::FloatRect Spaceship::get_current_position(){
    return this->sprite.getLocalBounds();
}

float Spaceship::get_centerX(){
    float centerX = (this->x + this->width) / 2.0;
    return centerX;
}

void Spaceship::update_health(int power){
    this->health += power;
}

int Spaceship::get_health(){
    return this->health;
}
