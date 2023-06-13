#include "structs_and_libraries.h"

int32_t team_count;
int32_t zombie_count;
int32_t survivor_count;

//User input. TODO: change method of input when implementing GUI.
int32_t teams_per_round;
int32_t num_of_rounds;

Segment* memory;

Team* teams;
Team* zombies;

struct Player_Tracker current_player;