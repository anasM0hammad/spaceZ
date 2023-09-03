//
//  utilities.cpp
//  spaceZ
//
//  Created by Mohammad Anas on 27/08/23.
//  Copyright © 2023 Mohammad Anas. All rights reserved.
//

#include <stdio.h>
#include "utilities.h"
#include "constants.h"

template<typename T>
void makeNull(std::vector<T*> arr){
    for(auto element: arr){
        if(element)
            delete element;
    }
    return;
}

void enemyCleanup(std::vector<Enemy*> enemies){
    int count = 0;
    for(auto enemy: enemies){
        if(enemy->getY() > WINDOW_HEIGHT){
            count++;
        }
    }
    
    if(count == enemies.size()){
        makeNull(enemies);
        enemies.clear();
    }
}
