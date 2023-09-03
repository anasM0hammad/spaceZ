//
//  blast.h
//  spaceZ
//
//  Created by Mohammad Anas on 27/08/23.
//  Copyright © 2023 Mohammad Anas. All rights reserved.
//

#ifndef blast_h
#define blast_h

#include <SFML/Graphics.hpp>


#endif /* blast_h */

class Blast {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    
public:
    Blast(float, float);
    void draw(sf::RenderWindow&);
};
