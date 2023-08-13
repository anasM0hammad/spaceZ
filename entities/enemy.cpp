//
//  enemy.cpp
//  spaceZ
//
//  Created by Mohammad Anas on 12/08/23.
//  Copyright © 2023 Mohammad Anas. All rights reserved.
//

#include <stdio.h>
#include "enemy.h"

Enemy::Enemy(float x, float y, sf::Sprite sprite, BuildType build_type, sf::Vector2f speed){
    this->x = x;
    this->y = y;
    this->sprite = sprite;
    this->build_type = build_type;
    this->height = ENEMY_HEIGHT;
    this->width = ENEMY_WIDTH;
    this->speed = speed;
    
    switch(this->build_type){
        case BuildType::BEGINNER:
            this->bullet_power = BEGINNER_ENEMY_BULLET_POWER;
            this->health = BEGINNER_ENEMY_HEALTH;
            break;
        case BuildType::INTERMEDIATE:
            this->bullet_power = INTERMEDIATE_ENEMY_BULLET_POWER;
            this->health = INTERMEDIATE_ENEMY_HEALTH;
            break;
        case BuildType::EXPERT:
            this->bullet_power = EXPERT_ENEMY_BULLET_POWER;
            this->health = EXPERT_ENEMY_HEALTH;
            break;
    }
}

void Enemy::update(){
    if(this->y < WINDOW_HEIGHT){
        this->y += this->speed.y;
    }
    this->sprite.setPosition(this->x, this->y);
}

void Enemy::update_health(int power){
    this->health += power;
}

int Enemy::get_health(){
    return this->health;
}

sf::FloatRect Enemy::get_current_position(){
    return this->sprite.getLocalBounds();
}

float Enemy::getX(){
    return this->x;
}

float Enemy::getY(){
    return this->y;
}
