//
//  spaceship.cpp
//  spaceZ
//
//  Created by Mohammad Anas on 11/08/23.
//  Copyright © 2023 Mohammad Anas. All rights reserved.
//

#include "spaceship.h"
#include "../utils/constants.h"

Spaceship::Spaceship(float x, float y){
    this->x = x;
    this->y = y;
    this->health = START_SPACESHIP_HEALTH;
    this->bullet_power = START_SPACESHIP_BULLET_POWER;
    this->texture.loadFromFile(ASSETSPATH + "spaceship.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setScale(0.15, 0.15);
    this->sprite.setPosition(this->x, this->y);
    this->height = this->texture.getSize().y * 0.15;
    this->width = this->texture.getSize().x * 0.15;
}

void Spaceship::reset(float x, float y){
    this->x = x;
    this->y = y;
    this->health = START_SPACESHIP_HEALTH;
    this->bullet_power = START_SPACESHIP_BULLET_POWER;
    sprite.setPosition(this->x, this->y);
}

//void Spaceship::move_left(){
//    if(this->x - this->speed.x <= 0){
//        this->x = 0;
//    }
//    else{
//        this->x = this->x - this->speed.x;
//    }
//    this->sprite.setPosition(this->x, this->y);
//    return;
//}
//
//void Spaceship::move_right(){
//    float cornerX = this->x + this->width;
//    if(cornerX + this->speed.x >= WINDOW_WIDTH){
//        this->x = WINDOW_WIDTH - this->width;
//    }
//    else{
//        this->x = this->x + this->speed.x;
//    }
//    this->sprite.setPosition(this->x, this->y);
//    return;
//}

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

float Spaceship::getY(){
    return this->y;
}

float Spaceship::getX(){
    return this->x;
}

void Spaceship::set_position(float x, float y){
    if(x >= 0 && (x + this->width) <= WINDOW_WIDTH){
        this->x = x;
    }
    this->y = y;
    this->sprite.setPosition(x, y);
}

void Spaceship::draw(sf::RenderWindow& window){
    window.draw(this->sprite);
}
