//
//  healthkit.cpp
//  spaceZ
//
//  Created by Mohammad Anas on 13/08/23.
//  Copyright © 2023 Mohammad Anas. All rights reserved.
//

#include <stdio.h>
#include "../utils/constants.h"
#include "healthkit.h"

HealthKit::HealthKit(float x, float y, sf::Sprite sprite, sf::Vector2f speed, int healthBoost){
    this->x = x;
    this->y = y;
    this->sprite = sprite;
    this->width = HEALTHKIT_WIDTH;
    this->height = HEALTHKIT_HEIGHT;
    this->speed = speed;
    this->healthBoost = healthBoost;
}

void HealthKit::update(){
    if(this->y + this->speed.y <= WINDOW_HEIGHT){
        this->y += this->speed.y;
    }
    
    this->sprite.setPosition(this->x, this->y);
}

float HealthKit::getX(){
    return this->x;
}

float HealthKit::getY(){
    return this->y;
}

sf::FloatRect HealthKit::get_position(){
    return this->sprite.getLocalBounds();
}
