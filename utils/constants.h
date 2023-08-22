//
//  constants.h
//  spaceZ
//
//  Created by Mohammad Anas on 11/08/23.
//  Copyright © 2023 Mohammad Anas. All rights reserved.
//

#ifndef constants_h
#define constants_h
#include <string>

static constexpr int WINDOW_WIDTH = 1200;
static constexpr int WINDOW_HEIGHT = 900;
static constexpr int START_SPACESHIP_HEALTH = 100;
static constexpr int START_SPACESHIP_BULLET_POWER = 1;

static constexpr float SPACESHIP_BULLET_SPEED = 5.0;
static constexpr int SPACESHIP_POWER = 1;

static constexpr int BEGINNER_ENEMY_BULLET_POWER = 1;
static constexpr int INTERMEDIATE_ENEMY_BULLET_POWER = 2;
static constexpr int EXPERT_ENEMY_BULLET_POWER = 3;

static constexpr int BEGINNER_ENEMY_HEALTH = 50;
static constexpr int INTERMEDIATE_ENEMY_HEALTH = 100;
static constexpr int EXPERT_ENEMY_HEALTH = 150;

static const std::string ASSETSPATH = "/Users/anas/Desktop/Projects/Cpp_Games/spaceZ/spaceZ/assets/";

static const std::string GAME_START_MSG = "Click to Start";
static const std::string GAME_PAUSED_MSG = "Paused. Click to Resume";

enum BuildType {
    BEGINNER,
    INTERMEDIATE,
    EXPERT
};

enum Direction{
    UP,
    DOWN,
    RIGHT,
    LEFT
};

enum GameState{
    READY, 
    RUNNING,
    PAUSED,
    COMPLETED
};

#endif /* constants_h */
