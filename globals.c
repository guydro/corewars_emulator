#include "structs_and_libraries.h"

int32_t team_count;
int32_t zombie_count;
int32_t survivor_count;

int32_t commands_ran;

//User input. TODO: change method of input when implementing GUI.
int32_t teams_per_round;
int32_t num_of_rounds;

Segment* memory;

Team* teams;
Team* zombies;

Team* teams_in_play;

int32_t teams_alive;
int32_t* team_permutation;

struct Player_Tracker current_player;