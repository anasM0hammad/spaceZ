//
//  utilities.h
//  spaceZ
//
//  Created by Mohammad Anas on 27/08/23.
//  Copyright © 2023 Mohammad Anas. All rights reserved.
//

#ifndef utilities_h
#define utilities_h

#include <vector>
#include "../entities/enemy.h"

template<typename T>
void makeNull(std::vector<T*>);

void enemyCleanup(std::vector<Enemy*>);

#endif /* utilities_h */
