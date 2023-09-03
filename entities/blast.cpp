//
//  blast.cpp
//  spaceZ
//
//  Created by Mohammad Anas on 27/08/23.
//  Copyright © 2023 Mohammad Anas. All rights reserved.
//

#include <stdio.h>
#include "blast.h"
#include "../utils/constants.h"

Blast::Blast(float x, float y){
    this->texture.loadFromFile(ASSETSPATH + "blast.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setScale(0.2, 0.2);
    this->sprite.setPosition(x, y);
}

void Blast::draw(sf::RenderWindow& window){
    window.draw(this->sprite);
}
