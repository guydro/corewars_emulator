#include "structs_and_libraries.h"

#ifndef COREWARSINTERPRETER_GLOBALS_H
#define COREWARSINTERPRETER_GLOBALS_H

extern struct Player_Tracker current_player;

extern int32_t team_count;
extern int32_t zombie_count;
extern int32_t survivor_count;

extern int32_t commands_ran;

//User input. TODO: change method of input when implementing GUI.
extern int32_t teams_per_round;
extern int32_t num_of_rounds;

extern Segment* memory;

extern Team* teams;
extern Team* zombies;

extern Team* teams_in_play;

extern int32_t teams_alive;
extern int32_t* team_permutation;

#endif //COREWARSINTERPRETER_GLOBALS_H
