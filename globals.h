#include "structs_and_libraries.h"

#ifndef COREWARSINTERPRETER_GLOBALS_H
#define COREWARSINTERPRETER_GLOBALS_H

extern struct Player_Tracker current_player;

extern int32_t team_count;
extern int32_t zombie_count;
extern int32_t survivor_count;

//User input. TODO: change method of input when implementing GUI.
extern int32_t teams_per_round;
extern int32_t num_of_rounds;

extern Segment* memory;

extern Team* teams;
extern Team* zombies;


#endif //COREWARSINTERPRETER_GLOBALS_H
