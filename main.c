#include "init.h"
#include "structs_and_libraries.h"
#include "globals.h"
#include "new_round.h"

int main() {
    init_usr_input();
    load_players();

    init_round(); // TODO: for testing purposes, in real game should run as a while loop condition.

    return 0;
}