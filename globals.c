#include "structs_libraries_and_macros.h"

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

Team* teams_in_play; // Includes zombies.

int32_t teams_alive; // Doesn't include zombies.
int32_t* team_permutation;

// globals.h also defines commands_per_round

int8_t* opcode_lookup_table;

struct Player_Tracker current_player;
