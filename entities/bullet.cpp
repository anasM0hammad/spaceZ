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

Bullet::Bullet(sf::Vector2f speed, int power, float x, float y, Direction direction){
    float scale = 0.0;
    this->x = x;
    this->y = y;
    this->power = power;
    this->speed = speed;
    if(direction == Direction::DOWN){
        this->texture.loadFromFile(ASSETSPATH + "laser-enemy.png");
        scale = 0.15;
    }
    else if(direction == Direction::UP){
        this->texture.loadFromFile(ASSETSPATH + "laser-spaceship.png");
        scale = 0.25;
        this->y -= this->texture.getSize().y * scale;
    }
    this->sprite.setTexture(this->texture);
    this->sprite.setScale(scale, scale);
    this->sprite.setPosition(this->x, this->y);
    this->width = this->texture.getSize().x * scale;
    this->height = this->texture.getSize().y * scale;
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
    return this->sprite.getGlobalBounds();
}

float Bullet::getX(){
    return this->x;
}

float Bullet::getY(){
    return this->y;
}

void Bullet::draw(sf::RenderWindow& window){
    window.draw(this->sprite);
}

int Bullet::getPower(){
    return this->power;
}
