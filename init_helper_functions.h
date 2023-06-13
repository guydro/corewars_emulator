#include "structs_and_libraries.h"
#include "globals.h"

#ifndef COREWARSINTERPRETER_INIT_HELPER_FUNCTIONS_H
#define COREWARSINTERPRETER_INIT_HELPER_FUNCTIONS_H

void init_survivor_and_team_count(void);
char* get_code(char* filename, char* dirname);
void add_survivor_to_team(Team* team, Survivor survivor);
void allocate_memory(void);

#endif //COREWARSINTERPRETER_INIT_HELPER_FUNCTIONS_H
