//
//  healthkit.h
//  spaceZ
//
//  Created by Mohammad Anas on 13/08/23.
//  Copyright © 2023 Mohammad Anas. All rights reserved.
//

#ifndef healthkit_h
#define healthkit_h
#include <SFML/Graphics.hpp>

class HealthKit{
private:
    int healthBoost;
    float height;
    float width;
    sf::Vector2f speed;
    float x;
    float y;
    sf::Sprite sprite;
    
public:
    HealthKit(float, float, sf::Sprite, sf::Vector2f, int);
    void update();
    float getX();
    float getY();
    sf::FloatRect get_position();
};

#endif /* healthkit_h */
