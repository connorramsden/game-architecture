#ifndef GAMEASSETS_H
#define GAMEASSETS_H

#include <string>

// Converts a string to its ascii / char values, and returns the sum of those values
int stringToASCII(std::string s);
int basicHashFunction(std::string s);

// Decent table size to hash-function with
const int HASH_MOD = 127;

const std::string ASSET_PATH = "Assets/";
const std::string GAME_FONT = "cour.ttf";
const std::string SNAKE_HEAD_UP_FILENAME = "snake_head_up.png";
const std::string SNAKE_HEAD_RIGHT_FILENAME = "snake_head_right.png";
const std::string SNAKE_HEAD_DOWN_FILENAME = "snake_head_down.png";
const std::string SNAKE_HEAD_LEFT_FILENAME = "snake_head_left.png";
const std::string SNAKE_BODY_FILENAME = "snake_body.png";
const std::string OBJECTIVE_FILENAME = "objective.png";
const std::string WALLS_FILENAME = "walls.png";

const int SNAKE_HEAD_UP_INDEX = basicHashFunction(SNAKE_HEAD_UP_FILENAME);
const int SNAKE_HEAD_RIGHT_INDEX = basicHashFunction(SNAKE_HEAD_RIGHT_FILENAME);
const int SNAKE_HEAD_DOWN_INDEX = basicHashFunction(SNAKE_HEAD_DOWN_FILENAME);
const int SNAKE_HEAD_LEFT_INDEX = basicHashFunction(SNAKE_HEAD_LEFT_FILENAME);
const int SNAKE_BODY_INDEX = basicHashFunction(SNAKE_BODY_FILENAME);
const int OBJECTIVE_INDEX = basicHashFunction(OBJECTIVE_FILENAME);
const int WALLS_INDEX = basicHashFunction(WALLS_FILENAME);

#endif