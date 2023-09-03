//
//  enemy.cpp
//  spaceZ
//
//  Created by Mohammad Anas on 12/08/23.
//  Copyright © 2023 Mohammad Anas. All rights reserved.
//

#include <stdio.h>
#include "enemy.h"

Enemy::Enemy(float x, float y, BuildType build_type){
    this->x = x;
    this->y = y;
    this->build_type = build_type;
    this->texture.loadFromFile(ASSETSPATH + "enemy.png");
    this->blastT.loadFromFile(ASSETSPATH + "blast.png");
    this->sprite.setTexture(this->texture);
    this->blastS.setTexture(this->blastT);
    this->sprite.setScale(0.2, 0.2);
    this->blastS.setScale(0.5, 0.5);
    this->sprite.setPosition(x, y);
    this->height = this->texture.getSize().y * 0.2;
    this->width = this->texture.getSize().x * 0.2;
    this->speed = {0, ENEMY_SPEED};
    this->alive = true;
    this->blastCount = 0;
    this->blastMusic.openFromFile(ASSETSPATH + "blast.ogg");
    
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
    if(this->y < WINDOW_HEIGHT && !blastCount){
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
    return this->sprite.getGlobalBounds();
}

float Enemy::getX(){
    return this->x;
}

float Enemy::getY(){
    return this->y;
}

void Enemy::draw(sf::RenderWindow& window){
    window.draw(this->sprite);
}

void Enemy::drawBlast(sf::RenderWindow& window){
    if(!this->isAlive() && this->blastCount < 700){
        this->blastCount++;
        this->blastS.setPosition(this->x, this->y);
        window.draw(this->blastS);
        if(this->blastCount == 1){
            this->blastMusic.play();
        }
    }
}

void Enemy::killed(){
    this->alive = false;
}

bool Enemy::isAlive(){
    return this->alive;
}

