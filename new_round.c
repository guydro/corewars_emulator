#include "globals.h"
#include "structs_and_libraries.h"


bool choose_teams() {
    static int32_t rounds_repeated = 0;
    if (rounds_repeated == num_of_rounds) return false;

    int carry = 1;
    for (int i=teams_per_round-1; i>=0 && carry; i--) {
        if (team_permutation[i] < team_permutation[i+1]-1) {
            team_permutation[i]++;
            carry = 0;

            for (int j=i+1; j<teams_per_round; j++) team_permutation[j] = team_permutation[j-1] + 1;
        }
    }

    if (carry) {
        rounds_repeated++;
        for (int i=0; i<teams_per_round; i++) team_permutation[i] = i;
    }

    for (int i=0; i<teams_per_round; i++) {
        teams_in_play[i] = teams[team_permutation[i]];
    }

    teams_alive = teams_per_round;
    return true;
}

void resurrect_players() {
    for(Team* team = teams_in_play; team < teams_in_play + teams_per_round; team++) {
        team->living_survivors[0] = true;
        if (team->survivors[1].initialized) {team->living_survivors[1] = true;}
        else {team->living_survivors[1] = false;}
    }
}

void reset_segments() {
    // TODO: Figure out which segments to actually reset
    memset(&memory[0], 0, sizeof(Segment));
}

void insert_players() {
    // TODO: EXTREMELY BAD IMPLEMENTATION!!! PLS FIX
    // Implement adam's linked lists sol
    bool occupied[0x10000];

    for(Team* team = teams_in_play; team < teams_in_play + teams_per_round; team++) {
        for(int i = 0; i < 2; i++) {
            if(!(team->living_survivors[i])) continue;

            bool found = false;

            while(!found) {
                int32_t location = rand() % (0x10000 - team->survivors[i].code_size);

                for(int j = location; j < location + team->survivors[i].code_size; j++) {
                    if(occupied[j]) goto skip;
                }

                found = true;
                
                // copy code to memory
                for(int k = 0; k < team->survivors[i].code_size; k++) {
                    memory[0].values[location + k] = team->survivors[i].code[k];
                    occupied[location + k] = true;
                }

                skip:
                    continue;
            }
        }
    }
}

bool init_round() {
    if (!choose_teams()) { return false; }
    
    resurrect_players();
    reset_segments();

    commands_ran = 0;

    current_player.team_id = 0;
    current_player.survivor_position = 0;

    insert_players();

    return true;
}