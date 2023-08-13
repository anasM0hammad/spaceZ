//
//  constants.h
//  spaceZ
//
//  Created by Mohammad Anas on 11/08/23.
//  Copyright © 2023 Mohammad Anas. All rights reserved.
//

#ifndef constants_h
#define constants_h

static constexpr int WINDOW_WIDTH = 1200;
static constexpr int WINDOW_HEIGHT = 1000;
static constexpr int START_SPACESHIP_HEALTH = 100;
static constexpr int START_SPACESHIP_BULLET_POWER = 1;
static constexpr float ENEMY_HEIGHT = 50.0;
static constexpr float ENEMY_WIDTH = 50.0;

static constexpr int BEGINNER_ENEMY_BULLET_POWER = 1;
static constexpr int INTERMEDIATE_ENEMY_BULLET_POWER = 2;
static constexpr int EXPERT_ENEMY_BULLET_POWER = 3;

static constexpr int BEGINNER_ENEMY_HEALTH = 50;
static constexpr int INTERMEDIATE_ENEMY_HEALTH = 100;
static constexpr int EXPERT_ENEMY_HEALTH = 150;

enum BuildType {
    BEGINNER,
    INTERMEDIATE,
    EXPERT
};

#endif /* constants_h */
